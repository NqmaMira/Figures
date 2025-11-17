#pragma once
#include "figure.h"

class figureFactory {
	public:
	virtual figure* readFigure(const std::string& description) = 0;
};