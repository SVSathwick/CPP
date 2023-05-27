#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mu;
std::condition_variable cv;
int i = 1;
int count = 0;
std::queue<int> container;
bool producerWait = false;
bool consumerWait = true;

void Producer(int lotSize, int totalSize)
{
	/*std::unique_lock<std::mutex> locker(mu);*/
	for (;i <= lotSize && count < totalSize;)
	{
		std::unique_lock<std::mutex> locker(mu);
		if (container.size() == lotSize)
		{
			consumerWait = false;
			producerWait = true;
		}
		cv.wait(locker, []() {return container.size() <=5; });
		std::cout << "Pushing " << i << " by " << std::this_thread::get_id() << std::endl;		
		container.push(i);
		i++;
		count++;
		/*locker.unlock();*/
		cv.notify_all();
	}
	//locker.unlock();
}

void Consumer()
{
	i = 1;
	while (true)
	{
		std::unique_lock<std::mutex> locker(mu);		
		cv.wait(locker, []() {return container.size() != 0; });
		if (container.size() == 0)
		{
			consumerWait = true;
			producerWait = false;
		}
		std::cout << "Popping " << container.front() << " by " << std::this_thread::get_id() << std::endl;
		container.pop();
		locker.unlock();
		cv.notify_all();

		if (container.size() == 0)
			break;
	}
}

int main()
{
	std::thread tProducer(Producer, 5, 10);
	std::thread tConsumer(Consumer);
	tProducer.join();
	tConsumer.join();

	getchar();
	return 0;
}