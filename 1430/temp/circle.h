#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "figure.h"
using namespace std;

class Circle : public Figure
{
public:
    Circle(double x, double y, double tempRadius) {
        center.set_coord(x,y);
        radius = tempRadius;
    };
    void draw() {
        cout << "A circle with center "  << center.print() << "and radius " << radius;
    };
    void rotation(double) {
        cout << "no effects."
    }

private:
    double radius;
};

#endif // CIRCLE_H
