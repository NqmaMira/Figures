#include "catch2/catch_all.hpp"
#include "circle.h"
#include "../src/compareDoubles.cpp"

TEST_CASE("Circle throws if perimeter is going to be too big", "[figure][circle]") {
	const double max = std::numeric_limits<double>::max();

	REQUIRE_THROWS_AS(circle(max), std::invalid_argument);
	REQUIRE_THROWS_AS(circle(max / 2), std::invalid_argument);
}
TEST_CASE("Circle throws if given radius equal to or lesser than zero", "[figure][circle]") {
	REQUIRE_THROWS_AS(circle(-1), std::invalid_argument);
	REQUIRE_THROWS_AS(circle(0), std::invalid_argument);
}
TEST_CASE("Circle returns correct perimeter", "[figure][circle]") {
	double r = 10;
	circle* c = new circle(r);
	double expected = 62.8;
	double p = c->perimeter();
	REQUIRE(compareDoubles(p, expected));
}