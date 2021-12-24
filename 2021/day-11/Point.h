#pragma once

class Point
{
private:
    int x, y, level;

public:
    Point();
    Point(int x, int y, int level);
    ~Point();

    int getX() const;
    int getY() const;

    void Print() const;

    // TODO flash function to increment
    void increment();
};

// TODO isAdjacent function to continue checking and repeating
bool isAdjacent