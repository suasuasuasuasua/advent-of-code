#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void solve();
bool openFile(ifstream &fileIn, const string &fileName);
vector<vector<int>> readFile(ifstream &fileIn);
void printVector(const vector<vector<int>> &fileData);

vector<int> lowestPoints(const vector<vector<int>> &fileData);
bool checkLowest(const vector<vector<int>> &fileData, int x, int y);

bool checkLeft(const vector<vector<int>> &fileData, int x, int y);
bool checkRight(const vector<vector<int>> &fileData, int x, int y);
bool checkAbove(const vector<vector<int>> &fileData, int x, int y);
bool checkBelow(const vector<vector<int>> &fileData, int x, int y);

int main()
{
    /* start here */
    solve();
}

void solve()
{
    ifstream fileIn;
    // string fileName = "../sample.txt";
    string fileName = "../input.txt";

    if (!openFile(fileIn, fileName))
    {
        cout << "File could not be opened" << endl;
        return;
    }

    vector<vector<int>> fileData = readFile(fileIn);
    // printVector(fileData);

    vector<int> partOneVector = lowestPoints(fileData);
    int partOneSummation = 0;
    for (auto &num : partOneVector)
    {
        partOneSummation += (1 + num);
    }
    cout << "Part 1: " << partOneSummation << endl;
}

bool openFile(ifstream &fileIn, const string &fileName)
{
    fileIn.open(fileName);
    if (fileIn)
    {
        return true;
    }
    return false;
}

vector<vector<int>> readFile(ifstream &fileIn)
{
    vector<vector<int>> fileData;
    while (!fileIn.eof())
    {
        string fileLine;
        getline(fileIn, fileLine);

        vector<int> fileDataLine;
        for (const auto &num : fileLine)
        {
            int charAsNum = static_cast<int>(num) % 48;
            fileDataLine.push_back(charAsNum);
        }
        fileData.push_back(fileDataLine);
    }
    return fileData;
}

void printVector(const vector<vector<int>> &fileData)
{
    for (const auto &line : fileData)
    {
        for (const auto &num : line)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

vector<int> lowestPoints(const vector<vector<int>> &fileData)
{
    vector<int> lowestPoints;
    for (int y = 0, ny = fileData.size(); y < ny; y++)
    {
        for (int x = 0, nx = fileData.at(y).size(); x < nx; x++)
        {
            if (checkLowest(fileData, x, y))
            {
                int lowest = fileData.at(y).at(x);
                lowestPoints.push_back(lowest);
            }
        }
    }
    return lowestPoints;
}

bool checkLowest(const vector<vector<int>> &fileData, int x, int y)
{
    if (checkLeft(fileData, x, y) && checkRight(fileData, x, y) && checkAbove(fileData, x, y) && checkBelow(fileData, x, y))
    {
        return true;
    }
    return false;
}

bool checkLeft(const vector<vector<int>> &fileData, int x, int y)
{
    if (x == 0)
    {
        return true;
    }
    int currentPoint = fileData.at(y).at(x);
    int pointToLeft = fileData.at(y).at(x - 1);
    if (currentPoint < pointToLeft)
    {
        return true;
    }
    return false;
}
bool checkRight(const vector<vector<int>> &fileData, int x, int y)
{
    int rowLength = fileData.at(y).size() - 1;
    if (x == rowLength)
    {
        return true;
    }
    int currentPoint = fileData.at(y).at(x);
    int pointToRight = fileData.at(y).at(x + 1);
    if (currentPoint < pointToRight)
    {
        return true;
    }
    return false;
}
bool checkAbove(const vector<vector<int>> &fileData, int x, int y)
{
    if (y == 0)
    {
        return true;
    }
    int currentPoint = fileData.at(y).at(x);
    int pointAbove = fileData.at(y - 1).at(x);
    if (currentPoint < pointAbove)
    {
        return true;
    }
    return false;
}
bool checkBelow(const vector<vector<int>> &fileData, int x, int y)
{
    int columnLength = fileData.size() - 1;
    if (y == columnLength)
    {
        return true;
    }
    int currentPoint = fileData.at(y).at(x);
    int pointBelow = fileData.at(y + 1).at(x);
    if (currentPoint < pointBelow)
    {
        return true;
    }
    return false;
}