#include <cstdlib>
#include <iostream>
#include <filesystem>

#include "triangle.h"
#include "circle.h"
#include "compareDoubles.cpp"

int main()
{
	double r = 10;
	circle* c = new circle(r);
	double expected = 62.8;
	double p = c->perimeter();
	std::cout << expected << " " << p;
	std::cout << std::endl << compareDoubles(expected, p);
	return 0;
}