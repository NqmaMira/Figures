#pragma once
#include "figureFactory.h"
#include "triangle.h"

class triangleFactory : public figureFactory {
	public:
		triangle* readFigure(const std::string& description) override;
};