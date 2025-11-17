#pragma once
#include "figureFactory.h"
#include <istream>
#include "figure.h"

class streamFigureFactory : public figureFactory {
private:
	std::istream& input;
public:
	streamFigureFactory(std::istream& in);
	figure* create() override;
	~streamFigureFactory() = default;
};