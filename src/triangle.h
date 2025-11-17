#pragma once
#include "figure.h"

class triangle : public figure {
private:
	double a;
	double b;
	double c;
public:
	triangle(double a, double b, double c);
	double perimeter() const override;
	virtual ~triangle() = default;
};