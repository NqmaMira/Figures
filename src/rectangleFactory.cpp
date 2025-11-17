#include "rectangleFactory.h"
#include <sstream>
#include <stdexcept>

rectangle* rectangleFactory::readFigure(const std::string& description) {
	std::istringstream stream(description);
	double width, height;
	if(stream.eof()) {
		throw std::invalid_argument("Invalid input, rectangle needs two double values!");
	}
	stream >> width;
	if(stream.fail() || stream.eof()) {
		throw std::invalid_argument("Invalid input, rectangle needs two double values!");
	}
	stream >> height;
	if(stream.fail() || !stream.eof()) {
		throw std::invalid_argument("Invalid input, rectangle needs two double values!");
	}
	return new rectangle(width, height);
}