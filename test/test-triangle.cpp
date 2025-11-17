#include "catch2/catch_all.hpp"
#include "triangle.h"
#include "../src/compareDoubles.cpp"

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
	double p = tr->perimeter();
	REQUIRE(compareDoubles(p, expected));
}
TEST_CASE("Triangle toString returns correct string", "[figure][triangle]") {
	double a = 40;
	double b = 60;
	double c = 30;
	triangle* tr = new triangle(a, b, c);
	std::string expected = "triangle 30.00 40.00 60.00";
	std::string str = tr->toString();
	REQUIRE(str == expected);
}
TEST_CASE("Triangle toString rounds correctly", "[figure][triangle]") {
	double a = 40.004;
	double b = 60.004;
	double c = 30.004;
	triangle* tr = new triangle(a, b, c);
	std::string expected = "triangle 30.00 40.00 60.00";
	std::string str = tr->toString();
	REQUIRE(str == expected);
	a = 40.005;
	b = 60.005;
	c = 30.005;
	tr = new triangle(a, b, c);
	expected = "triangle 30.01 40.01 60.01";
	str = tr->toString();
	REQUIRE(str == expected);
}
TEST_CASE("Triangle clone works correctly", "[figure][triangle]") {
	double a = 25;
	double b = 35;
	double c = 45;
	triangle* tr1 = new triangle(a, b, c);
	triangle* tr2 = tr1->clone();
	REQUIRE(tr1 != tr2);
	REQUIRE(compareDoubles(tr1->perimeter(), tr2->perimeter()));
	REQUIRE(tr1->toString() == tr2->toString());
}
TEST_CASE("Triangle copy constructor throws on nullptr", "[figure][triangle]") {
	triangle* tr = nullptr;
	REQUIRE_THROWS_AS(triangle(tr), std::invalid_argument);
}