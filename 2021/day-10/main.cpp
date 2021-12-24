#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void solve();
bool openFile(ifstream &fileIn, const string &fileName);
vector<string> readFile(ifstream &fileIn);
int checkChunk(const string &chunk);
bool checkStack(const stack<char> &stackSymbol, const char &symbol);

map<char, char> parens = {{'}', '{'}, {')', '('}, {']', '['}, {'>', '<'}};

int main()
{
    /* start here */
    solve();
}

void solve()
{
    ifstream fileIn;
    string fileName = "../sample.txt";

    if (!openFile(fileIn, fileName))
    {
        cout << "File could not be opened for reading" << endl;
        return;
    }

    vector<string> fileData = readFile(fileIn);
    // part 1
    int partOne = 0;
    for (auto &line : fileData)
    {
        partOne += checkChunk(line);
    }
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

vector<string> readFile(ifstream &fileIn)
{
    vector<string> fileData;
    while (!fileIn.eof())
    {
        string line;
        getline(fileIn, line);
        fileData.push_back(line);
    }
    return fileData;
}

int checkChunk(const string &chunk)
{
    int score;
    stack<char> symbolStack;

    for (const auto &symbol : chunk)
    {
        symbolStack.push(symbol);
        // cout << symbol << endl;
    }

    return score;
}

bool checkStack(const stack<char> &stackSymbol, const char &symbol)
{
    auto tempStack = stackSymbol;
    // iterate through stack
    return false;
}