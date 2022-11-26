#include <iostream>
#include "Point.h"

using namespace std;

Point::Point()
{
    x = y = 0;
}
Point::Point(int x, int y, int level)
{
    this->x = x;
    this->y = y;
    this->level = level;
}

Point::~Point()
{
}

int Point::getX() const
{
    return this->x;
}
int Point::getY() const
{
    return this->y;
}

void Point::Print() const
{
    cout << "X: " << x << " Y: " << y << " Level: " << level << endl;
}

void Point::increment()
{
}