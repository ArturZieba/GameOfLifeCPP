#include "GOL.h"
#include <iostream> //For cout
//#include <cstdlib> //For rand - theoretically not needed, iostream > istream > ostream > ios > xlocnum already includes cstdlib, but it's still good practice to state includes explicitly
#include <random> //Contains superior randomization functions to rand() and srand() in <cstdlib>

int main()
{
	GOL::DrawGrid();
	Cell::IsAlive();
}

//TEMP: Draw a grid in the Console
void GOL::DrawGrid()
{
	std::default_random_engine Generator; //Random number generator
	std::bernoulli_distribution Distribution; //Bernoulli distribution for bool - there should be around 50:50 true:false distribution without (double) stated in the declaration

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			//Generates a random boolean based on the randomly generated number with a set distribution (should be 50:50)
			std::cout << (Distribution(Generator)) ? "1" : "0";

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