#include "circleFactory.h"
#include "circle.h"
#include <sstream>
#include <stdexcept>

circle* circleFactory::readFigure(const std::string& description) {
	std::istringstream stream(description);
	double radius;
	stream >> radius;
	if(stream.fail() || !stream.eof()) {
		throw std::invalid_argument("Invalid input, circle needs one double value!");
	}
	return new circle(radius);
}