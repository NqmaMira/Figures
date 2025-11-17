#include "circle.h"
#include <stdexcept>
#include <cmath>

const double PI = 3.14;

circle::circle(double r) {
	if (r <= 0)
		throw std::invalid_argument("Radius must be greater than 0!");
	if (std::isinf(2 * PI * r))
		throw std::invalid_argument("Radius is too large!");
	radius = r;
}

double circle::perimeter() const {
	return 2 * PI * radius;
}
