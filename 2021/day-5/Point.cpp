#include "Point.h"
#include <iostream>

using namespace std;

void Point::print()
{
    cout << " X: " << this->x << " Y: " << this->y;
}

bool operator<(const Point &lhs, const Point &rhs)
{
    if (lhs.x < rhs.x || lhs.y < rhs.y)
    {
        return true;
    }
    return false;
}