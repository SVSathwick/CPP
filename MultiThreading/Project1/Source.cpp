#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

std::mutex g_mutex;

void threadFunc()
{
	using namespace std::chrono_literals;
	{
		std::lock_guard<mutex> lock(g_mutex);
		std::cout << "Running thread: " << std::this_thread::get_id() << endl;
	}

	std::this_thread::yield();
	std::this_thread::sleep_for(2s);
	{
		std::lock_guard<mutex> lock(g_mutex);
		std::cout << "Running thread: " << std::this_thread::get_id() << endl;
	}
}

void test_self_lock()
{
	//std::lock_guard<mutex> lock(g_mutex);
	if (g_mutex.try_lock())
	{
		std::cout << "1 - Thread ID: " << std::this_thread::get_id() << endl;
		g_mutex.unlock();
	}
	

	//std::lock_guard<mutex> lock2(g_mutex);
	/*if (g_mutex.try_lock())
	{
		std::cout << "2 - Thread ID: " << std::this_thread::get_id() << endl;
		g_mutex.unlock();
	}*/
}

std::recursive_mutex g_rMutex;
void test_recursive_mutex()
{
	g_rMutex.lock();
	std::cout << "1 - Thread ID: " << std::this_thread::get_id() << endl;

	g_rMutex.lock();
	std::cout << "2 - Thread ID: " << std::this_thread::get_id() << endl;
}

int main()
{
	std::thread thread1(test_self_lock);
	//thread1.join();
	thread1.detach();
	//getchar();

	/*std::thread thread2(test_recursive_mutex);
	thread2.join();*/

	/*std::vector<std::thread> threads;
	for (int i = 0; i < 3; i++)
	{
		threads.emplace_back(threadFunc);
	}

	for (auto& it : threads)
	{
		it.join();
	}*/
	cout << "Main ThreadID: " << std::this_thread::get_id() << endl;
	std::this_thread::sleep_for(2s);

	return 0;
}