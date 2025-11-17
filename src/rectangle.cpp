#include "rectangle.h"
#include <stdexcept>
#include <cmath>

rectangle::rectangle(double w, double h) {
	if (w <= 0 || h <= 0)
		throw std::invalid_argument("Width and height must be greater than 0!");
	if (std::isinf(2 * (w + h)))
		throw std::invalid_argument("Width and/or height are too large!");
	width = w;
	height = h;
}

double rectangle::perimeter() const {
	return 2 * (width + height);
}