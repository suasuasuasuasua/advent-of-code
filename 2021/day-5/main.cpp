#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Point.h"

using namespace std;

void solve();
bool readFile(ifstream &fileIn, const string &fileName);
vector<int> readFile(ifstream &fileIn);
vector<pair<Point, Point>> makePoints(const vector<int> &fileData);
void mark(map<Point, int> &mapData, pair<Point, Point> &pairPoints, const int &part);
bool isHorizontal(const Point &lp, const Point &rp);
bool isVertical(const Point &lp, const Point &rp);
int countMap(const map<Point, int> &mapData);
bool isLeftDiagonal(const Point &lp, const Point &rp);
bool isRightDiagonal(const Point &lp, const Point &rp);
void printMap(const map<Point, int> &mapData);

int main()
{
    solve();
}

void solve()
{
    ifstream fileIn;
    string fileName = "../sample.txt";
    // string fileName = "../input.txt";

    if (readFile(fileIn, fileName) == -1)
    {
        cout << "Error. Problem reading file." << endl;
        return;
    }

    vector<int> fileData = readFile(fileIn);
    vector<pair<Point, Point>> pointsData = makePoints(fileData);
    map<Point, int> mapData;
    // for (auto &pairPoints : pointsData)
    // {
    //     mark(mapData, pairPoints, 1);
    // }
    // // Part 1: find intersections of horizontal and vertical points
    // cout << "Part 1: " << countMap(mapData) << endl;
    // Part 2: find intersections of diagonal points as well
    mapData.clear();
    for (auto &pairPoints : pointsData)
    {
        mark(mapData, pairPoints, 2);
    }
    cout << "Part 2: " << countMap(mapData) << endl;

    printMap(mapData);
}

bool readFile(ifstream &fileIn, const string &fileName)
{
    fileIn.open(fileName);
    if (!fileIn)
    {
        return -1;
    }
    return 0;
}

vector<int> readFile(ifstream &fileIn)
{
    vector<int> fileData;

    while (!fileIn.eof())
    {
        int num;
        fileIn >> num;
        if (fileIn.fail())
        {
            fileIn.clear();
            fileIn.ignore();
            continue;
        }
        fileData.push_back(num);
    }
    return fileData;
}

vector<pair<Point, Point>> makePoints(const vector<int> &fileData)
{
    vector<pair<Point, Point>> pointsData;
    for (int i = 0; i < fileData.size();)
    {
        Point first, second;
        int x1, y1, x2, y2;

        x1 = fileData.at(i);
        y1 = fileData.at(i + 1);
        x2 = fileData.at(i + 2);
        y2 = fileData.at(i + 3);

        i += 4;

        first.x = x1;
        first.y = y1;
        second.x = x2;
        second.y = y2;

        if (!isHorizontal(first, second) && !isVertical(first, second) && !isLeftDiagonal(first, second) && !isRightDiagonal(first, second))
        {
            continue;
        }

        pointsData.push_back(make_pair(first, second));
    }
    cout << endl
         << endl;
    return pointsData;
}

void mark(map<Point, int> &mapData, pair<Point, Point> &pairPoints, const int &part)
{
    auto first = pairPoints.first, second = pairPoints.second;

    int x1, y1, x2, y2;
    x1 = first.x;
    y1 = first.y;
    x2 = second.x;
    y2 = second.y;

    vector<Point> pointsToMark;
    if (isHorizontal(first, second))
    {
        if (x1 < x2)
        {
            for (int i = x1; i <= x2; i++)
            {
                pointsToMark.push_back(Point(i, y1));
            }
        }
        if (x2 < x1)
        {
            for (int i = x2; i <= x1; i++)
            {
                pointsToMark.push_back(Point(i, y1));
            }
        }
    }
    if (isVertical(first, second))
    {
        if (y1 < y2)
        {
            for (int i = y1; i <= y2; i++)
            {
                pointsToMark.push_back(Point(x1, i));
            }
        }
        if (y2 < y1)
        {
            for (int i = y2; i <= y1; i++)
            {
                pointsToMark.push_back(Point(x1, i));
            }
        }
    }

    if (part == 2)
    {
        if (isLeftDiagonal(first, second))
        {
            if (x1 == y1 && x2 == y2)
            {
                if (x2 < x1)
                {
                    int temp = x1;
                    x1 = x2;
                    x2 = temp;
                }
                for (int i = x1; i <= x2; i++)
                {
                    pointsToMark.push_back(Point(i, i));
                }
            }
            else if (first < second)
            {
                int j = y1;
                for (int i = x1; i <= x2; i++)
                {
                    pointsToMark.push_back(Point(i, j));
                    j++;
                }
            }
            else
            {
                int j = y2;
                for (int i = x2; i <= x1; i++)
                {
                    pointsToMark.push_back(Point(i, j));
                    j++;
                }
            }
        }
        if (isRightDiagonal(first, second))
        {
            // 0,5 -> 3,1
            // 3,2 -> 5,0
            // 3,3 -> 6,0
            if (x1 < x2 && y1 > y2)
            {
                int j = y1;
                for (int i = x1; i <= x2; i++)
                {
                    pointsToMark.push_back(Point(i, j));
                    j--;
                }
            }
            // 3,1 -> 0,5
            // 3,2 -> 5,0
            // 3,3 -> 6,0

            // 8,0 -> 0,8
            else
            {
                int j = y2;
                // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                for (int i = x2; i <= x1; i++)
                {
                    // cout << i << " " << j << endl;
                    pointsToMark.push_back(Point(i, j));
                    j--;
                }
            }
        }
        cout << endl;
    }

    for (auto &point : pointsToMark)
    {
        point.print();
        cout << endl;
        mapData[point]++;
    }
}

bool isHorizontal(const Point &lp, const Point &rp)
{
    int y1, y2;
    y1 = lp.y;
    y2 = rp.y;
    if (y1 == y2)
    {
        cout << "is horizontal" << endl;
        return true;
    }
    return false;
}

bool isVertical(const Point &lp, const Point &rp)
{
    int x1, x2;
    x1 = lp.x;
    x2 = rp.x;
    if (x1 == x2)
    {
        cout << "Is vertical" << endl;
        return true;
    }
    return false;
}

int countMap(const map<Point, int> &mapData)
{
    int sum = 0;
    for (const auto &data : mapData)
    {
        auto point = data.first;
        auto count = data.second;

        if (count >= 2)
        {
            sum++;
        }
    }
    return sum;
}

// 0,0 -> 2,2 || 2,2 -> 0,0
// 0,1 -> 1,2 || 1,2 -> 0,1
// 0,2 -> 1,3 || 1,3 -> 0,2
// 1,0 -> 2,1 || 2,1 -> 1,0
bool isLeftDiagonal(const Point &lp, const Point &rp)
{
    double x1, y1, x2, y2;
    x1 = lp.x;
    y1 = lp.y;
    x2 = rp.x;
    y2 = rp.y;

    if (x1 - x2 == 0 || y1 - y2 == 0)
    {
        return false;
    }

    if (!(lp < rp))
    {
        int tempX, tempY;
        tempX = x2;
        x2 = x1;
        x1 = tempX;

        tempY = y2;
        y2 = y1;
        y1 = tempY;
    }
    double slope = (y2 - y1) / (x2 - x1);
    if (slope == 1.0)
    {
        cout << "Is left diagonal" << endl;
        return true;
    }

    return false;
}

// (0,4 -> 2,2) 0,4 1,3 2,2
// (3,1 -> 4,0) 0,4 1,3 2,2 3,1
// (3,2 -> 4,1) 3,2 4,1

// (4,1 -> 3,2) 3,2 4,1
// (2,2 -> 0,4) 0,4 1,3 2,2
bool isRightDiagonal(const Point &lp, const Point &rp)
{
    double x1, y1, x2, y2;
    x1 = lp.x;
    y1 = lp.y;
    x2 = rp.x;
    y2 = rp.y;

    if (x1 - x2 == 0 || y1 - y2 == 0)
    {
        return false;
    }

    double slope = (y2 - y1) / (x2 - x1);
    if (slope == -1.0)
    {
        cout << "Is right diagonal" << endl;
        return true;
    }
    return false;
}

void printMap(const map<Point, int> &mapData)
{
    int largestX = 0, largestY = 0;
    for (auto &dat : mapData)
    {
        auto point = dat.first;
        int x, y;
        x = point.x;
        y = point.y;

        if (x > largestX)
        {
            largestX = x;
        }
        if (y > largestY)
        {
            largestY = y;
        }
    }
    cout << largestX << " " << largestY << endl;
}