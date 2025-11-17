#pragma once
#include "figureFactory.h"
#include "rectangle.h"

class rectangleFactory : public figureFactory {
	public:
		rectangle* readFigure(const std::string& description) override;
};