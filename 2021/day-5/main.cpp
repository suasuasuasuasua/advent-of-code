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
bool isInLine(const int &x1, const int &y1, const int &x2, const int &y2);

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

        if (!isInLine(x1, y1, x2, y2))
        {
            continue;
        }

        first.x = x1;
        first.y = y1;
        second.x = x2;
        second.y = y2;

        pointsData.push_back(make_pair(first, second));
    }
    return pointsData;
}

bool isInLine(const int &x1, const int &y1, const int &x2, const int &y2)
{
    if (x1 == x2 || y1 == y2)
    {
        return true;
    }
    return false;
}