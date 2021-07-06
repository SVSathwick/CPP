#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <exception>

using namespace std;

vector<exception_ptr> g_exceptions;
mutex g_mutex;

void func1()
{
	throw std::runtime_error("exception 1");
}
void func2()
{
	throw std::runtime_error("exception 2");
}
void thread_func1()
{
	try
	{
		func1();
	}
	catch (...)
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		g_exceptions.push_back(std::current_exception());
	}
}
void thread_func2()
{
	try
	{
		func2();
	}
	catch (...)
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		g_exceptions.push_back(std::current_exception());
	}
}

int main()
{
	std::thread t1(thread_func1);
	std::thread t2(thread_func2);
	t1.join();
	t2.join();
	for (auto const& e : g_exceptions)
	{
		try
		{
			if (e != nullptr)
				std::rethrow_exception(e);
		}
		catch (std::exception const& ex)
		{
			std::cout << ex.what() << '\n';
		}
	}
	return 0;
}