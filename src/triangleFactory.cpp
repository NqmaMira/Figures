#include "triangleFactory.h"
#include <sstream>
#include <stdexcept>

triangle* triangleFactory::readFigure(const std::string& description) {
	std::istringstream stream(description);
	double a, b, c;
	if(stream.eof()) {
		throw std::invalid_argument("Invalid input, triangle needs three double values!");
	}
	stream >> a;
	if(stream.fail() || stream.eof()) {
		throw std::invalid_argument("Invalid input, triangle needs three double values!");
	}
	stream >> b;
	if(stream.fail() || stream.eof()) {
		throw std::invalid_argument("Invalid input, triangle needs three double values!");
	}
	stream >> c;
	if(stream.fail() || !stream.eof()) {
		throw std::invalid_argument("Invalid input, triangle needs three double values!");
	}
	return new triangle(a, b, c);
}