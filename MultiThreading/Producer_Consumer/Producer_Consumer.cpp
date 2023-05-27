#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void producer(int n) {
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] {return ready; });

    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";
    std::cout << "WorkerThread - ThreadID: " << std::this_thread::get_id() << " Data:" << data << std::endl;
    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed, processed= " << processed << "\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

void consumer() {
    data = "Example data";
    // send data to the worker thread
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing, ready= " << ready << ", processed: " << processed << "\n";
        std::cout << "MainThread -  ThreadID: " << std::this_thread::get_id() << " Data:" << data << std::endl;
    }
    cv.notify_one();

    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        std::cout << "MainThread waiting for worker to signal, ready= " << ready << ", processed: " << processed << "\n";
        cv.wait(lk, [] {return processed; });
    }
    std::cout << "MainThread -  ThreadID: " << std::this_thread::get_id() << " Data:" << data << std::endl;
    std::cout << "MainThread got signal from worker thread, ready= " << ready << ", processed: " << processed << "\n";
}
int main() {

    std::thread tProducer(producer);
    tProducer.join();
}