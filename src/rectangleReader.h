#pragma once
#include "figureReader.h"
#include "rectangle.h"

class rectangleReader : public figureReader {
	public:
		rectangle* readFigure(const std::string& description) override;
};