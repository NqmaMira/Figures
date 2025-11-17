#include "catch2/catch_all.hpp"
#include "rectangle.h"
#include "../src/compareDoubles.cpp"

TEST_CASE("Rectangle throws if perimeter is going to be too big", "[figure][rectangle]") {
	const double max = std::numeric_limits<double>::max();
	REQUIRE_THROWS_AS(rectangle(max, 1), std::invalid_argument);
	REQUIRE_THROWS_AS(rectangle(1, max), std::invalid_argument);
	REQUIRE_THROWS_AS(rectangle(max / 2, max / 2), std::invalid_argument);
}
TEST_CASE("Rectangle throws if given width or height equal to or lesser than zero", "[figure][rectangle]") {
	REQUIRE_THROWS_AS(rectangle(-1, 1), std::invalid_argument);
	REQUIRE_THROWS_AS(rectangle(1, -1), std::invalid_argument);
	REQUIRE_THROWS_AS(rectangle(0, 1), std::invalid_argument);
	REQUIRE_THROWS_AS(rectangle(1, 0), std::invalid_argument);
}
TEST_CASE("Rectangle returns correct perimeter", "[figure][rectangle]") {
	double w = 20;
	double h = 30;
	rectangle* rect = new rectangle(w, h);
	double expected = 100;
	double p = rect->perimeter();
	REQUIRE(compareDoubles(p, expected));
}