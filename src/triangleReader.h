#pragma once
#include "figureReader.h"
#include "triangle.h"

class triangleReader : public figureReader {
	public:
		triangle* readFigure(const std::string& description) override;
};