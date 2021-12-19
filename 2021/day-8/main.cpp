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
    solve();
}

void solve()
{
    ifstream fileIn;
    string fileName = "../input.txt";
    // string fileName = "../sample.txt";
    if (!openFile(fileIn, fileName))
    {
        cout << fileName << " could not be opened." << endl;
        return;
    }

    // part 1
    vector<string> digitData = readFile(fileIn, 1);
    cout << "Part 1: " << digitData.size() << endl;
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
    while (!fileIn.eof())
    {
        string dataLine;
        getline(fileIn, dataLine);

        int breakpoint = dataLine.find("|") + 2; // +2 to start at the character after the bar
        int lengthOfRest = dataLine.size() - breakpoint;
        dataLine = dataLine.substr(breakpoint, lengthOfRest);

        // split string into many strings
        vector<string> splitDigits;
        int space;
        string parsedDigit;

        while ((space = dataLine.find(' ')) != string::npos)
        {
            parsedDigit = dataLine.substr(0, space);

            space++;
            lengthOfRest = dataLine.size() - space;
            dataLine = dataLine.substr(space, lengthOfRest);

            splitDigits.push_back(parsedDigit);
        }

        // add the last word after parsed for spaces
        // because the first loop stops after no more spaces are found
        splitDigits.push_back(dataLine);

        for (const auto& digit : splitDigits)
        {
            if (partOneDigits(digit))
            {
                data.push_back(digit);
            }
        }
    }
    return data;
}

bool partOneDigits(const string &digit)
{
    int digitSize = digit.size();
    // 1, 4, 7, 8, in that order
    vector<int> digitCheck = {2, 4, 3, 7};
    for (const auto& digit : digitCheck)
    {
        if (digit == digitSize)
        {
            return true;
        }
    }
    return false;
}