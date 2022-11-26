#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Point.h"

void solve();
bool openFile(ifstream &fileIn, string fileName);
vector<vector<int>> readFile(ifstream &fileIn);
void printMatrix(const vector<vector<int>> &matrix);
void printPointMatrix(const vector<vector<Point>> &matrix);
vector<vector<Point>> toPointMatrix(const vector<vector<int>> &matrix);

int main()
{
    solve();
}

void solve()
{
    ifstream fileIn;
    string fileName = "../sample.txt";
    // string fileName = "../input.txt"

    if (!openFile(fileIn, fileName))
    {
        cout << "File could not be opened for reading." << endl;
        return;
    }

    vector<vector<int>> intMatrix = readFile(fileIn);
    // changes matrix of integers to matrix of Points
    vector<vector<Point>> pointMatrix = toPointMatrix(intMatrix);
    printPointMatrix(pointMatrix);
}

bool openFile(ifstream &fileIn, string fileName)
{
    fileIn.open(fileName);
    if (!fileIn)
    {
        return false;
    }
    return true;
}

vector<vector<int>> readFile(ifstream &fileIn)
{
    vector<vector<int>> fileData;
    while (!fileIn.eof())
    {
        vector<int> fileLine;
        string line;
        getline(fileIn, line);
        for (const auto &c : line)
        {
            int charAsNum = static_cast<int>(c) % 48;
            fileLine.push_back(charAsNum);
        }
        fileData.push_back(fileLine);
    }
    return fileData;
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &line : matrix)
    {
        for (const auto &num : line)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

void printPointMatrix(const vector<vector<Point>> &matrix)
{
    for (const auto& line : matrix)
    {
        for (const auto& point : line)
        {
            point.Print();
        }
        cout << endl;
    }
}

vector<vector<Point>> toPointMatrix(const vector<vector<int>> &matrix)
{
    vector<vector<Point>> pointMatrix;
    int level;
    for (int y = 0, ny = matrix.size(); y < ny; y++)
    {
        vector<Point> linePoints;
        for (int x = 0, nx = matrix.at(y).size(); x < nx; x++)
        {
            level = matrix.at(y).at(x);
            linePoints.push_back(Point(x, y, level));
        }
        pointMatrix.push_back(linePoints);
    }
    return pointMatrix;
}