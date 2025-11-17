#include "catch2/catch_all.hpp"
#include "randomFigureFactory.h"
#include "../src/compareDoubles.cpp"
#include <string>
#include "figure.h"
#include <set>

TEST_CASE("Random figure factory creates different figures", "[figure][randfactory]") {
	randomFigureFactory factory;
	const int numFigures = 100;
	std::set<std::string> figureStrings;
	for (int i = 0; i < numFigures; ++i) {
		figure* fig = factory.create();
		std::string figStr = fig->toString();
		figureStrings.insert(figStr);
		delete fig;
	}
	REQUIRE(figureStrings.size() > 1);
}

TEST_CASE("Random figure factory creates valid figures", "[figure][randfactory]") {
	randomFigureFactory factory;
	const int numFigures = 50;
	for (int i = 0; i < numFigures; ++i) {
		figure* fig = factory.create();
		REQUIRE(fig != nullptr);
		double p = fig->perimeter();
		REQUIRE(p > 0);
		std::string figStr = fig->toString();
		REQUIRE(!figStr.empty());
		delete fig;
	}
}

TEST_CASE("Random figure factory creates figures of different types and with normal distribution", "[figure][randfactory]") {
	randomFigureFactory factory;
	const int numFigures = 1000;
	int circleCount = 0;
	int triangleCount = 0;
	int rectangleCount = 0;
	for (int i = 0; i < numFigures; ++i) {
		figure* fig = factory.create();
		std::string figStr = fig->toString();
		if (figStr.find("circle") == 0) {
			++circleCount;
		} else if (figStr.find("triangle") == 0) {
			++triangleCount;
		} else if (figStr.find("rectangle") == 0) {
			++rectangleCount;
		}
		delete fig;
	}
	REQUIRE(circleCount > 0);
	REQUIRE(triangleCount > 0);
	REQUIRE(rectangleCount > 0);
	REQUIRE(circleCount < numFigures * 0.6);
	REQUIRE(triangleCount < numFigures * 0.6);
	REQUIRE(rectangleCount < numFigures * 0.6);
}

TEST_CASE("Random figure factory creates figures within expected range", "[figure][randfactory]") {
	randomFigureFactory factory;
	const int numFigures = 50;
	for (int i = 0; i < numFigures; ++i) {
		figure* fig = factory.create();
		std::string figStr = fig->toString();
		std::istringstream stream(figStr);
		std::string figureType;
		stream >> figureType;
		if (figureType == "circle") {
			double radius;
			stream >> radius;
			REQUIRE(radius > 1);
			REQUIRE(radius < 100);
		} else if (figureType == "triangle") {
			double a, b, c;
			stream >> a >> b >> c;
			REQUIRE(a > 1);
			REQUIRE(b > 1);
			REQUIRE(c > 1);
		} else if (figureType == "rectangle") {
			double width, height;
			stream >> width >> height;
			REQUIRE(width > 1);
			REQUIRE(height > 1);
		}
		delete fig;
	}
}