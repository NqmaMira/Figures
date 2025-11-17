#pragma once
#include "figure.h"

class circle : public figure{
private:
	double radius;
public:
	circle(double r);
	circle(const circle* c);
	double perimeter() const override;
	virtual ~circle() = default;
	std::string toString() const override;
	circle* clone() const override;
};