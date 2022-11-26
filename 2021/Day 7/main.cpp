#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void solve();
bool openFile(ifstream &fileIn, const string &fileName);
vector<int> readFile(ifstream &fileIn);
unsigned long long int leastDistance(const vector<int> &crabPositions, const int &part);
unsigned long long int summation(const int &currPosition, const int &proposedPosition);

int main()
{
    solve();
}

void solve()
{
    ifstream fileIn;
    string fileName = "../input.txt";
    // string fileName = "../sample.txt";

    if (!openFile(fileIn, fileName))
    {
        cout << "File could not be opened" << endl;
        return;
    }

    vector<int> crabPositions = readFile(fileIn);

    // part 1
    int fuelSpent = leastDistance(crabPositions, 1);
    cout << "Part 1: " << fuelSpent << endl;

    // part 2
    fuelSpent = leastDistance(crabPositions, 2);
    cout << "Part 2: " << fuelSpent << endl;
}

bool openFile(ifstream &fileIn, const string &fileName)
{
    fileIn.open(fileName);
    if (!fileIn)
    {
        return false;
    }
    return true;
}

vector<int> readFile(ifstream &fileIn)
{
    vector<int> fileData;
    while (!fileIn.eof())
    {
        int temp;
        fileIn >> temp;
        if (!fileIn)
        {
            fileIn.clear();
            fileIn.ignore();
            continue;
        }
        fileData.push_back(temp);
    }
    return fileData;
}

unsigned long long int leastDistance(const vector<int>& crabPositions, const int &part)
{
    int maxPosition, minPosition;
    maxPosition = minPosition = crabPositions.front();

    for (const auto &position : crabPositions)
    {
        if (position > maxPosition)
        {
            maxPosition = position;
        }
        if (position < minPosition)
        {
            minPosition = position;
        }
    }

    unsigned long long int minFuel = __LONG_MAX__;

    for (int i = minPosition, n = maxPosition; i < n; i++)
    {
        unsigned long long int tempMin = 0;
        for (const auto &position : crabPositions)
        {
            if (part == 1)
            {
                tempMin += abs(position - i);
            }
            else
            {
                tempMin += summation(position, i);
            }
        }
        if (tempMin < minFuel)
        {
            minFuel = tempMin;
        }
    }
    return minFuel;
}

unsigned long long int summation(const int &currPosition, const int &proposedPosition)
{
    unsigned long long int sum = 0, difference;
    difference = abs(currPosition - proposedPosition);

    for (int i = 1, n = difference; i <= n; i++)
    {
        sum += i;
    }

    return sum;
}