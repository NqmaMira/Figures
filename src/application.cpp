#include <cstdlib>
#include <iostream>
#include <filesystem>

#include "triangle.h"
#include "circle.h"
#include "compareDoubles.cpp"
#include "stringToFigure.h"
#include "streamFigureFactory.h"

int main()
{
	std::istringstream input("triangle 3.0 4.0 5.0\n");
	streamFigureFactory factory(input);
	figure* fig = factory.create();
	std::cout << fig->toString() << "\n";
	delete fig;
	return 0;
}