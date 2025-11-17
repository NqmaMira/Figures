#include "randomFigureFactory.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <random>

figure* randomFigureFactory::create() {
    std::random_device rd;
    std::mt19937 gen(rd());
	std::uniform_int_distribution<> figDis(0, 2);
    int figType = figDis(gen);
    switch (figType) {
        case 0: { // circle
            std::uniform_real_distribution<> radiusDis(1.0, 100.0);
            double radius = radiusDis(gen);
            return new circle(radius);
        }
        case 1: { // rectangle
            std::uniform_real_distribution<> dimDis(1.0, 100.0);
            double width = dimDis(gen);
            double height = dimDis(gen);
            return new rectangle(width, height);
        }
        case 2: { // triangle
            std::uniform_real_distribution<> sideDis(1.0, 100.0);
            double a, b, c;
            do {
                a = sideDis(gen);
                b = sideDis(gen);
                c = sideDis(gen);
            } while (a + b <= c || a + c <= b || b + c <= a); // ensure valid triangle
            return new triangle(a, b, c);
        }
	}
}
