#pragma once
#include "figureFactory.h"
#include "circle.h"

class circleFactory : public figureFactory {
	public:
	circle* readFigure(const std::string& description) override;
};