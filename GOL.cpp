#include "GOL.h"
#include <iostream> //For cout
#include <cstdlib> //For rand - theoritically not needed, iostream > istream > ostream > ios > xlocnum already includes cstdlib, but it's still good practice to state includes explicitly


int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			std::cout << (std::rand() % 2) ? "1" : "0";

			if (j == 9)
			{
				std::cout << std::endl;
			}
		}
	}
}