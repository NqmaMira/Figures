#include "triangle.h"
#include <stdexcept>
//#include <math.h>

void swapIfGreater(double& a, double& b) {
	if (a > b) {
		a += b;
		b = a - b;
		a = b - a;
	}
}

triangle::triangle(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0)
		throw std::invalid_argument("Sides need to be a number > 0!");

	swapIfGreater(a, b);
	swapIfGreater(a, c);
	swapIfGreater(b, c);

	if (isinf(a + b + c))
		throw std::invalid_argument("The sum of the sides must be less then the max double!");

	if (a + b <= c)
		throw std::invalid_argument("The sum of any two sides of a triangle must be greater than the third side!");

	this->a = a;
	this->b = b;
	this->c = c;

}

double triangle::perimeter() const{
	return a + b + c;
}
