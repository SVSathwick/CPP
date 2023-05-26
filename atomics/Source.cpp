#include <atomic>
#include <iostream>
#include <thread> 
using namespace std;

// atomic variable
atomic <int> temp(0);

// thread one adds 5 in the temp.
void thread_one()
{
	cout << "Inside Thread_one.\n";
	temp += 5;
	cout << "from thread one " << temp << "\n";
}

// thread two subtracts 5 in the temp. 
void thread_two()
{
	cout << "Inside Thread_two.\n";
	temp -= 5;
	cout << "from thread two " << temp << "\n";
}

//driver 
int main()
{
	// initiating threads
	thread th1(thread_one);
	thread th2(thread_two);

	// waiting for the threads to end.
	th1.join();
	th2.join();
}