#include <random>
#include <ctime>
#include "Utilities/ClientU.h"


int main()
{
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