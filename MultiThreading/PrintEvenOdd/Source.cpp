#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mu;
std::condition_variable cv;
int count = 1;

void PrintOdd(int size)
{
	for (; count < size;)
	{
		std::unique_lock<std::mutex> lock(mu, std::defer_lock); //Deferred locking
		lock.lock();
		cv.wait(lock, []() { return count % 2 == 1; });
		std::cout << "Count " << count << ", threadID: " << std::this_thread::get_id() << std::endl;
		count++;
		lock.unlock();
		cv.notify_all();
	}

}
void PrintEven(int size)
{
	for(;count < size;)
	{
		std::unique_lock<std::mutex> lock(mu);
		cv.wait(lock, []() { return count % 2 == 0; });
		std::cout << "Count " << count << ", threadID: " << std::this_thread::get_id() << std::endl;
		count++;
		lock.unlock();
		cv.notify_all();
	}
}



int main()
{
	int size = 10;	
	std::thread tOdd(PrintOdd, size);
	std::thread tEven(PrintEven, size);
	tOdd.join();
	tEven.join();

	//getchar() will ensure that main thread doesn't exist until worker threads finish
	//{
		//tOdd.detach();
		//tEven.detach();
		//getchar();
		
		//When we try to interrupt(type something and press enter) using getchar() 
		// while the worker threads are working, the main thread crashes with the below error
		//Count 2679, threadID: 27244
		//Count 2680, threadID: 8748
		//Count 2d : \agent\_work\3\s\src\vctools\crt\github\stl\src\mutex.cpp(64) : mutex destroyed while busy6
		//81, threadID : 27244
		//Count 2682, threadID : 8748
		//Count 2683, threadID : 27244
		
		// But when we type something and press enter after the worker threads finis their work
		// the main thread works as expected and stops
		 
		// In the above code, detach clearly makes the worker threads independent 
		// and even if the main thread crashes they continue doing their job
	//}
	
	return 0;
}