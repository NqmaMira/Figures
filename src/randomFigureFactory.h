#pragma once
#include "figureFactory.h"

class randomFigureFactory : public figureFactory {
	public:
		figure* create() override;
		~randomFigureFactory() = default;
};