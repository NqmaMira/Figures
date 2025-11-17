#pragma once
#include "figure.h"

class figureReader {
	public:
	virtual figure* readFigure(const std::string& description) = 0;
};