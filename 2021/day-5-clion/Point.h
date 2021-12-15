//
// Created by Justin on 12/15/2021.
//

#ifndef DAY_5_CLION_POINT_H
#define DAY_5_CLION_POINT_H


#include <iostream>

class Point
{
public:
    int x, y;
    void print();
    Point(int x, int y) : x(x), y(y) {}
    Point()
    {
        x = 0;
        y = 0;
    }
};

bool operator<(const Point &lhs, const Point &rhs);
bool operator==(const Point &lhs, const Point &rhs);


#endif //DAY_5_CLION_POINT_H
