#include "streamFigureFactory.h"
#include "stringToFigure.h"
#include <stdexcept>
#include <istream>
#include <string>

streamFigureFactory::streamFigureFactory(std::istream& inputStream) : input(inputStream) {}

figure* streamFigureFactory::create() {
	std::string line;
	if (!std::getline(input, line)) {
		throw std::invalid_argument("Failed to read figure from stream!");
	}
	stringToFigure converter;
	return converter.createFrom(line);
}