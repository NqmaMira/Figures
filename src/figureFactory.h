#pragma once
#include "figure.h"

class figureFactory {
public:
	virtual figure* create() = 0;
	virtual ~figureFactory() = default;
};