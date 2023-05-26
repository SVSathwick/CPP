#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

//using namespace std;

std::mutex mu;
std::condition_variable cv;
int n = 1;

using namespace std;

void PrintOdd(int size)
{
	for (; n < size;)
	{
		std::unique_lock<std::mutex> lock(mu);
		cv.wait(lock, []() { return n % 2 == 1; });
		string str("Thread-1 ");
		str = str + std::to_string(n)+'\n';
		
		string myText;
		ofstream myFile("filename.txt", ios::app);
		myFile << str.c_str();
		myFile.close();

		n++;
		lock.unlock();
		cv.notify_all();
	}

}
void PrintEven(int size)
{
	for (; n < size;)
	{
		std::unique_lock<std::mutex> lock(mu);
		cv.wait(lock, []() { return n % 2 == 0; });

		string str("Thread-2 ");
		str = str + std::to_string(n)+'\n';

		string myText;
		ofstream myFile("filename.txt", ios::app);
		myFile << str.c_str();
		myFile.close();

		n++;
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

	return 0;
}