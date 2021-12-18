#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void solve();
bool openFile(ifstream &fileIn, const string &fileName);
vector<string> readFile(ifstream &fileIn, const int &part);
bool partOneDigits(const string &digit);

int main()
{
    solve;
}

void solve()
{
    ifstream fileIn;
    string fileName;
    if (!fileIn)
    {
        cout << fileName << " could not be opened." << endl;
        return;
    }

    // part 1
    vector<string> digitData = readFile(fileIn, 1);
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

vector<string> readFile(ifstream &fileIn, const int &part)
{
    vector<string> data;
    bool output = false;
    while (!fileIn.eof())
    {
        string digit;
        fileIn >> digit;
        if (digit == "|")
        {
            output = true;
        }
        else
        {
            continue;
        }
        if (partOneDigits(digit))
        {
        }
    }
    return data;
}

bool partOneDigits(const string &digit)
{
    int digitSize = digit.size();
    if (digitSize == 1 || digitSize == 4 || digitSize == 7 || digitSize == 8)
    {
        return true;
    }
    return false;
}