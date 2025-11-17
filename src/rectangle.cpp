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

rectangle::rectangle(const rectangle* rect) {
	if (rect == nullptr)
		throw std::invalid_argument("Nullptr exception!");
	width = rect->width;
	height = rect->height;
}

double rectangle::perimeter() const {
	return 2 * (width + height);
}

std::string rectangle::toString() const {
	std::string num_text = std::to_string(width + 0.005);
	std::string rounded = num_text.substr(0, num_text.find(".") + 3);
	std::string result = "rectangle " + rounded + " ";
	num_text = std::to_string(height + 0.005);
	rounded = num_text.substr(0, num_text.find(".") + 3);
	result += rounded;
	return result;
}

rectangle* rectangle::clone() const {
	return new rectangle(*this);
}