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
TEST_CASE("Rectangle toString returns correct string", "[figure][rectangle]") {
	double w = 20;
	double h = 30;
	rectangle* rect = new rectangle(w, h);
	std::string expected = "rectangle 20.00 30.00";
	std::string str = rect->toString();
	REQUIRE(str == expected);
}
TEST_CASE("Rectangle toString rounds correctly", "[figure][rectangle]") {
	double w = 20.004;
	double h = 30.004;
	rectangle* rect = new rectangle(w, h);
	std::string expected = "rectangle 20.00 30.00";
	std::string str = rect->toString();
	REQUIRE(str == expected);
	w = 20.005;
	h = 30.005;
	rect = new rectangle(w, h);
	expected = "rectangle 20.01 30.01";
	str = rect->toString();
	REQUIRE(str == expected);
}
TEST_CASE("Rectangle clone works correctly", "[figure][rectangle]") {
	double w = 25;
	double h = 35;
	rectangle* rect1 = new rectangle(w, h);
	rectangle* rect2 = rect1->clone();
	REQUIRE(rect1 != rect2);
	REQUIRE(compareDoubles(rect1->perimeter(), rect2->perimeter()));
	REQUIRE(rect1->toString() == rect2->toString());
}
TEST_CASE("Rectangle copy constructor throws on nullptr", "[figure][rectangle]") {
	rectangle* rect = nullptr;
	REQUIRE_THROWS_AS(rectangle(rect), std::invalid_argument);
}