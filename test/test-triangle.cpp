#include "catch2/catch_all.hpp"
#include "triangle.h"

#include <array>

#include <chrono>

TEST_CASE("Triangle throws if given sides that added up are not greater than the other one", "[figure][triangle]") {
	REQUIRE_THROWS_AS(triangle(1, 2, 3), std::invalid_argument);
	REQUIRE_THROWS_AS(triangle(2, 1, 3), std::invalid_argument);
	REQUIRE_THROWS_AS(triangle(2, 3, 1), std::invalid_argument);
}
TEST_CASE("Triangle throws if sum of sides is too big", "[figure][triangle]") {
	const double max = std::numeric_limits<double>::max();

	REQUIRE_THROWS_AS(triangle(max, max, 1), std::invalid_argument);
	REQUIRE_THROWS_AS(triangle(max, 1, max), std::invalid_argument);
	REQUIRE_THROWS_AS(triangle(1, max, max), std::invalid_argument);

	REQUIRE_THROWS_AS(triangle(1, max/2, max/2), std::invalid_argument);
	REQUIRE_THROWS_AS(triangle(max/2, 1, max/2), std::invalid_argument);
	REQUIRE_THROWS_AS(triangle(max/2, max/2, 1), std::invalid_argument);
}
TEST_CASE("Triangle throws if given sides equal to or lesser than zero", "[figure][triangle]") {
	REQUIRE_THROWS_AS(triangle(-1, 1, 1), std::invalid_argument);
	REQUIRE_THROWS_AS(triangle(1, -1, 1), std::invalid_argument);
	REQUIRE_THROWS_AS(triangle(1, 1, -1), std::invalid_argument);
}
TEST_CASE("Triangle return correct perimeter", "[figure][triangle]") {
	double a = 40;
	double b = 60;
	double c = 30;
	triangle* tr = new triangle(a, b, c);
	double expected = 130;
	double p = tr->perimeter;
	REQUIRE(p == expected);
}