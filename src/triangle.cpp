#include "triangle.h"
#include <stdexcept>
#include <cmath>

void swapIfGreater(double& a, double& b) {
	if (a > b) {
		double temp = a;
		a = b;
		b = temp;
	}
}

triangle::triangle(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0)
		throw std::invalid_argument("Sides need to be a number > 0!");

	swapIfGreater(a, b);
	swapIfGreater(a, c);
	swapIfGreater(b, c);

	if (std::isinf(a + b + c))
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

std::string triangle::toString() const {
	std::string num_text = std::to_string(a + 0.005);
	std::string rounded = num_text.substr(0, num_text.find(".") + 3);
	std::string result = "triangle " + rounded + " ";
	num_text = std::to_string(b + 0.005);
	rounded = num_text.substr(0, num_text.find(".") + 3);
	result += rounded + " ";
	num_text = std::to_string(c + 0.005);
	rounded = num_text.substr(0, num_text.find(".") + 3);
	result += rounded;
	return result;
}
