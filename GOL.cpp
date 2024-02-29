#include "GOL.h"
#include <iostream> //For cout
#include <cstdlib> //For rand - theoritically not needed, iostream > istream > ostream > ios > xlocnum already includes cstdlib, but it's still good practice to state includes explicitly
//#include <random> //TEMP: Apparently should be used instead of rand()/srand() from <cstdlib>, check out further

int main()
{
	GOL::DrawGrid();
	Cell::IsAlive();
}

//TEMP: Draw a grid in the Console
void GOL::DrawGrid()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			//TEMP: std::rand should not be used, look for some implementation from <random>
			std::cout << (std::rand() % 2) ? "1" : "0";

			if (j == 9)
			{
				std::cout << std::endl;
			}
		}
	}
}

//TEMP: Print a string to the Console, currently to check function call from both GOL and Cell classes
void Cell::IsAlive()
{
	std::cout << "Dead or Alive";
	std::cout << std::endl;
}