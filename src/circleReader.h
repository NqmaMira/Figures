#pragma once
#include "figureReader.h"
#include "circle.h"

class circleReader : public figureReader {
	public:
	circle* readFigure(const std::string& description) override;
};