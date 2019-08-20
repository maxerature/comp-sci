#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class Figure
{
public:
    Figure(double x=0, double y=0) {
        center.set_coord(x,y);
    };
    Point location() {return center;};
    void move(Point tempCenter) {center = tempCenter; draw()};
    virtual void draw() = 0;
    virtual void rotate(double) = 0;
private:
    Point center;
};

#endif // FIGURE_H
