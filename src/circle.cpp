#include "circle.h"
#include <stdexcept>
#include <cmath>
#include <sstream>

const double PI = 3.14;

circle::circle(double r) {
	if (r <= 0)
		throw std::invalid_argument("Radius must be greater than 0!");
	if (std::isinf(2 * PI * r))
		throw std::invalid_argument("Radius is too large!");
	radius = r;
}

circle::circle(const circle* c) {
	if(c == nullptr)
		throw std::invalid_argument("Nullptr exception!");
	radius = c->radius;
}

double circle::perimeter() const {
	return 2 * PI * radius;
}

std::string circle::toString() const {
	std::string num_text = std::to_string(radius + 0.005);
	std::string rounded = num_text.substr(0, num_text.find(".") + 3);
	std::string result = "circle " + rounded;
	return result;
}

circle* circle::clone() const {
	return new circle(*this);
}