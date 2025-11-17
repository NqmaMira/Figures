#include "catch2/catch_all.hpp"
#include "stringToFigure.h"
#include "../src/compareDoubles.cpp"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

TEST_CASE("stringToFigure creates circle correctly", "[stringToFigure][circle]") {
	stringToFigure factory;
	figure* fig = factory.createFrom("circle 10.0");
	circle* c = dynamic_cast<circle*>(fig);
	REQUIRE(c != nullptr);
	double expectedPerimeter = 62.8;
	REQUIRE(compareDoubles(c->perimeter(), expectedPerimeter));
	std::string expectedString = "circle 10.00";
	REQUIRE(c->toString() == expectedString);
	delete fig;
}
TEST_CASE("stringToFigure creates triangle correctly", "[stringToFigure][triangle]") {
	stringToFigure factory;
	figure* fig = factory.createFrom("triangle 3.0 4.0 5.0");
	triangle* tr = dynamic_cast<triangle*>(fig);
	REQUIRE(tr != nullptr);
	double expectedPerimeter = 12.0;
	REQUIRE(compareDoubles(tr->perimeter(), expectedPerimeter));
	std::string expectedString = "triangle 3.00 4.00 5.00";
	REQUIRE(tr->toString() == expectedString);
	delete fig;
}
TEST_CASE("stringToFigure creates rectangle correctly", "[stringToFigure][rectangle]") {
	stringToFigure factory;
	figure* fig = factory.createFrom("rectangle 20.0 30.0");
	rectangle* rect = dynamic_cast<rectangle*>(fig);
	REQUIRE(rect != nullptr);
	double expectedPerimeter = 100.0;
	REQUIRE(compareDoubles(rect->perimeter(), expectedPerimeter));
	std::string expectedString = "rectangle 20.00 30.00";
	REQUIRE(rect->toString() == expectedString);
	delete fig;
}
TEST_CASE("stringToFigure throws on unknown figure type", "[stringToFigure]") {
	stringToFigure factory;
	REQUIRE_THROWS_AS(factory.createFrom("unknown 10.0"), std::invalid_argument);
}
TEST_CASE("stringToFigure throws on invalid format", "[stringToFigure]") {
	stringToFigure factory;
	REQUIRE_THROWS_AS(factory.createFrom("circle"), std::invalid_argument);
	REQUIRE_THROWS_AS(factory.createFrom("triangle 3.0 4.0"), std::invalid_argument);
	REQUIRE_THROWS_AS(factory.createFrom("rectangle 20.0"), std::invalid_argument);
	REQUIRE_THROWS_AS(factory.createFrom("rectangle aaa"), std::invalid_argument);
}
