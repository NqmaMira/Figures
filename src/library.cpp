#include "library.h"
#include <stdexcept>

unsigned int fibonacci(int n)
{
	if (n < 0) 
		throw std::invalid_argument("Number should be above 0");
	if (n == 0 || n == 1)
		return n;
	int a = 0, b = 1, c = a + b;
	for (int i = 2; i < n; i++) {
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}

unsigned int factorial(int n)
{
	if (n < 0)
		throw std::invalid_argument("Number should be above 0");
	if (n == 1 || n == 0)
		return 1;
	return factorial(n - 1) * n;
}
