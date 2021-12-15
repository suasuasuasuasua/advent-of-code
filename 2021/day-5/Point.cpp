#include "Point.h"
#include <iostream>

using namespace std;

void Point::print()
{
    cout << " X: " << this->x << " Y: " << this->y;
}

bool operator<(const Point &lhs, const Point &rhs)
{
    int x1, y1, x2, y2;
    x1 = lhs.x;
    y1 = lhs.y;
    x2 = rhs.x;
    y2 = rhs.y;

    // better comparator via https://stackoverflow.com/questions/1112531/what-is-the-best-way-to-use-two-keys-with-a-stdmap
    // not sure why this is the best way, but it works
    if (x1 != x2)
    {
        return x1 < x2;
    }
    else
    {
        return y1 < y2;
    }
 