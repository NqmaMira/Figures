#include "stringToFigure.h"
#include "circleReader.h"
#include "triangleReader.h"
#include "rectangleReader.h"
#include <stdexcept>
#include <sstream>

figure* stringToFigure::createFrom(std::string representation) {
	size_t pos = representation.find(' ');
	if (pos == std::string::npos) {
		throw std::invalid_argument("Invalid representation format!");
	}
	//std::string figureType = representation.substr(0, pos);
	//std::string params = representation.substr(pos + 1);
	std::istringstream stream(representation);
	std::string figureType;
	stream >> figureType;
	//std::istringstream iss(params);
	figureReader* factory = nullptr;
	if (figureType == "circle") {
		factory = new circleReader();
	} else if (figureType == "triangle") {
		factory = new triangleReader();
	} else if (figureType == "rectangle") {
		factory = new rectangleReader();
	} else {
		throw std::invalid_argument("Unknown figure type: " + figureType);
	}
	figure* fig = factory->readFigure(representation.substr(pos + 1));
	delete factory;
	return fig;
}