#pragma once
#include "figure.h"

class circle : public figure{
private:
	double radius;
public:
	circle(double r);
	double perimeter() const override;
	virtual ~circle() = default;
};