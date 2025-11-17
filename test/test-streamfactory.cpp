#include "catch2/catch_all.hpp"
#include "streamFigureFactory.h"
#include "figure.h"
#include "../src/compareDoubles.cpp"
#include <sstream>

TEST_CASE("streamFigureFactory creates circle correctly", "[figurefactory][streamfactory][circle]") {
	std::istringstream input("circle 10.0\n");
	streamFigureFactory factory(input);
	figure* fig = factory.create();
	REQUIRE(fig != nullptr);
	REQUIRE(fig->toString() == "circle 10.00");
	REQUIRE(compareDoubles(fig->perimeter(), 62.8));
	delete fig;
}
TEST_CASE("streamFigureFactory creates triangle correctly", "[figurefactory][streamfactory][triangle]") {
	std::istringstream input("triangle 3.0 4.0 5.0\n");
	streamFigureFactory factory(input);
	figure* fig = factory.create();
	REQUIRE(fig != nullptr);
	REQUIRE(fig->toString() == "triangle 3.00 4.00 5.00");
	REQUIRE(compareDoubles(fig->perimeter(), 12.0));
	delete fig;
}
TEST_CASE("streamFigureFactory creates rectangle correctly", "[figurefactory][streamfactory][rectangle]") {
	std::istringstream input("rectangle 20.0 30.0\n");
	streamFigureFactory factory(input);
	figure* fig = factory.create();
	REQUIRE(fig != nullptr);
	REQUIRE(fig->toString() == "rectangle 20.00 30.00");
	REQUIRE(compareDoubles(fig->perimeter(), 100.0));
	delete fig;
}
TEST_CASE("streamFigureFactory throws on invalid circle input", "[figurefactory][streamfactory][circle]") {
	std::istringstream input("invalidInput\n");
	streamFigureFactory factory(input);
	REQUIRE_THROWS_AS(factory.create(), std::invalid_argument);
}
TEST_CASE("streamFigureFactory throws on invalid triangle input", "[figurefactory][streamfactory][triangle]") {
	std::istringstream input("1.0 2.0\n");
	streamFigureFactory factory(input);
	REQUIRE_THROWS_AS(factory.create(), std::invalid_argument);
}
TEST_CASE("streamFigureFactory throws on invalid rectangle input", "[figurefactory][streamfactory][rectangle]") {
	std::istringstream input("10.0\n");
	streamFigureFactory factory(input);
	REQUIRE_THROWS_AS(factory.create(), std::invalid_argument);
}