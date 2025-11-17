#pragma once
#include "stringConvertible.h"
#include "cloneable.h"

class figure : public stringConvertible, public cloneable {
public:
	virtual double perimeter() const = 0;
	virtual ~figure() = default;
};