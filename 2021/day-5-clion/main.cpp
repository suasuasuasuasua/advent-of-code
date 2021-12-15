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
void mark(map<Point, int> &mapData, pair<Point, Point> &point);
bool isHorizontal(const Point &lp, const Point &rp);
bool isVertical(const Point &lp, const Point &rp);
int countMap(const map<Point, int> &mapData);
bool isLeftDiagonal(const Point &lp, const Point &rp);
bool isRightDiagonal(const Point &lp, const Point &rp);

int main()
{
    solve();
}

void solve()
{
    ifstream fileIn;
    string fileName = "../sample.txt";
    // string fileName = "../input1";

    if (readFile(fileIn, fileName) == -1)
    {
        cout << "Error. Problem reading file." << endl;
        return;
    }

    vector<int> fileData = readFile(fileIn);
    vector<pair<Point, Point>> pointsData = makePoints(fileData);
    map<Point, int> mapData;
    for (auto &pairPoints : pointsData)
    {
        mark(mapData, pairPoints);
    }
    // Part 1: find intersections of horizontal and vertical points
    cout << "Part 1: " << countMap(mapData) << endl;
    // Part 2: find intersections of diagonal points as well
    pointsData.clear();
    pointsData = makePoints(fileData);
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

        if (!isHorizontal(first, second) && !isVertical(first, second))
        {
            continue;
        }

        pointsData.push_back(make_pair(first, second));
    }
    return pointsData;
}

void mark(map<Point, int> &mapData, pair<Point, Point> &pairPoints)
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

    for (auto &point : pointsToMark)
    {
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

bool isLeftDiagonal(const Point &lp, const Point &rp)
{
    return false;
}
bool isRightDiagonal(const Point &lp, const Point &rp)
{
    return false;
}