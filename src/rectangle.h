#pragma once
#include "figure.h"

class rectangle : public figure {
private:
	double width;
	double height;
public:
	rectangle(double width, double height);
	rectangle(const rectangle* rect);
	double perimeter() const override;
	virtual ~rectangle() = default;
	std::string toString() const override;
	rectangle* clone() const override;
};