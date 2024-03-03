#include <algorithm> //For std::generate()
#include <array> //For std::array<>
//#include <cstdlib> //For std::rand() - theoretically not needed, iostream > istream > ostream > ios > xlocnum already includes cstdlib, but it's still good practice to state includes explicitly
#include <iostream> //For std::cout
#include <random> //Contains superior randomization functions to rand() and srand() in <cstdlib>
#include <Windows.h> //For system("cls") and sleep();


//Game Of Life grid dimensions - static so that it is accessible without GOL instance, const beacuse the std::array size is not dynamic 
static const int GRID_SIZE_X = 32;
static const int GRID_SIZE_Y = 20;

//TEMP: Set as static so that instance of parent class is not needed to call this function
void DrawGrid();
//TEMP:
bool CheckNeighbours(std::array<std::array<int, GRID_SIZE_Y>, GRID_SIZE_X>& grid);

int main()
{
	DrawGrid();
	
}

bool CheckNeighbours(std::array<std::array<int, GRID_SIZE_Y>, GRID_SIZE_X>& grid)
{
	int AliveNeighbours = 0; //Count how many cells around are alive
	int x;
	int y;

	for (x = -1; x <= 1; x++)
	{
		for (y = -1; y <= 1; y++)
		{
			if (!((x == 0) && (y == 0)))
			{
				if (grid[x][y]) AliveNeighbours += 1;
			}
		}
	}

	if (grid[x][y] == 1 && AliveNeighbours < 2) return true;//Any live cell with fewer than two live neighbors dies, as if by underpopulation.
	if (grid[x][y] == 1 && (AliveNeighbours == 2 || AliveNeighbours == 3)) return true;//Any live cell with two or three live neighbors lives on to the next generation.
	if (grid[x][y] == 1 && AliveNeighbours > 3) return false;//Any live cell with more than three live neighbors dies, as if by overpopulation.
	if (grid[x][y] == 0 && AliveNeighbours == 3) return true;//Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

	return false;
}

//TEMP: Draw a grid in the Console
void DrawGrid()
{
	std::default_random_engine generator; //Random number generator
	std::bernoulli_distribution distribution; //Bernoulli distribution for bool - there should be around 50:50 true:false distribution without (double) stated in the declaration
	
	//Game Of Life grid arrays - using std::array<> instead of int[][] because of added functionality
	std::array<std::array<int, GRID_SIZE_Y>, GRID_SIZE_X> gridPrinted{}; //Grid that is printed to the Console
	std::array<std::array<int, GRID_SIZE_Y>, GRID_SIZE_X> gridCalculated{}; //"Buffer" grid that is used for calculating cells states

	//Range-based for loop to randomly populate the GridPrinted array; auto& to deduce the element type instead of typing template in and & because there is no need for more copies of this array, just the modification of it
	for (auto& Element : gridPrinted)
	{
		//std::generate fills a container in a specified range (.begin/.end - iterators pointing to first/past-the-end elements) with values generated by the specified generator function object - used lambda expression here
		//Lambda contains has in [&]() so that Generator/Distribution are in its capture list
		//Distribution(Generator) Generates a random boolean based on the randomly generated number with a set distribution (should be 50:50)
		//TEMP: Maybe change lambda to a regular function?
		std::generate(Element.begin(), Element.end(), [&]() { return distribution(generator) ? 1 : 0; });
	}

	while (true) {
		//Check generated array elements
		for (auto& a : gridPrinted)
		{
			for (auto& b : a)
			{
				std::cout << b;
			}
			std::cout << std::endl;
		}

		for (auto& a : gridCalculated)
		{
			for (auto& b : a)
			{
				/*
				if (CheckNeighbours(gridPrinted)) { gridCalculated[a][b] = 1; }
				else { gridCalculated[a][b] = 0; }
				*/
			}
		}

		Sleep(500); //Wait x milliseconds
		system("cls"); //Clear Console
	}
}


