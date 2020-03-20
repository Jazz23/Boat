#include <random>
#include <ctime>
#include "Utilities/ClientU.h"

size_t SortNumberByDigit(int num, int digit)
{
	return (int)(num / pow(10, (digit))) % 10;
}

int main()
{
	int meme = 12345;

	for (int i = 0; i < 10; i++)
	{
		std::cout << SortNumberByDigit(meme, i) << ' ';
	}
	system("pause");
	return -1;

	srand((int)time(NULL));
	Boat::Start();
	system("pause");
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 1;

	system("pause");
}