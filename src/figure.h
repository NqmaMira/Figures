#pragma once
#include "stringConvertible.h"

class figure : public stringConvertible {
public:
	virtual double perimeter() const = 0;
	virtual ~figure() = default;
};