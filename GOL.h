//Declaring in separate header to tidy up the source file and not take up space above int main() for declarations
//Split classes for Game of Life and Cells to tidy up variables/functions further

#pragma once

class GOL
{
//TEMP: Public because it has to be accessible outside the class (i.e. int main()) and there is no need to make it private here and call it by proxy using other public functions (kind of like Getters and Setters for private variables)
public:
	//Game Of Life grid dimensions - static so that it is accessible without GOL instance, const beacuse the std::array size is not dynamic 
	static const int GridSizeX = 32;
	static const int GridSizeY = 20;

	//TEMP: Set as static so that instance of parent class is not needed to call this function
	static void DrawGrid();
};

class Cell
{
public:
	static void IsAlive();
};


