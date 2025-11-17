#pragma once
#include <cmath>
#include <cfloat>

//checks if two doubles are equal

inline bool compareDoubles(double first, double second)
{
    return std::fabs(first - second) <= DBL_EPSILON * std::fmax(std::fabs(first), std::fabs(second));
}