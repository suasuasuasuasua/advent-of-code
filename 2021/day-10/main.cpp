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
int checkChunk(const string &chunk, const int &part);
void printStack(const stack<char> &stackSymbol, const char &curr);

map<char, char> parens = {{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};
map<char, int> points = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};

int main()
{
    /* start here */
    solve();
}

void solve()
{
    ifstream fileIn;
    string fileName = "../sample.txt";
    // string fileName = "../input.txt";

    if (!openFile(fileIn, fileName))
    {
        cout << "File could not be opened for reading" << endl;
        return;
    }

    vector<string> fileData = readFile(fileIn);

    // part 1
    int partOne = 0;
    for (const auto &line : fileData)
    {
        partOne += checkChunk(line, 1);
    }
    cout << "Part 1: " << partOne << endl;

    // part 2
    int partTwo = 0;
    for (const auto &line : fileData)
    {
        partTwo *= 5;
        partTwo += checkChunk(line, 2);
    }
    cout << "Part 2: " << partTwo << endl;
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

int checkChunk(const string &chunk, const int &part)
{
    int score = 0;
    stack<char> symbolStack;

    // TODO move part 1 and 2 to separate functions
    for (const auto &symbol : chunk)
    {
        // if the current symbol is closing
        if (parens.count(symbol))
        {
            // if the previous symbol is equal to the closing symbol's corresponding opening
            // i.e. '}' to '{'
            // remove the previous symbol and don't add the current symbol because they matched
            if (symbolStack.top() == parens.at(symbol))
            {
                symbolStack.pop();
            }
            // stops at the first incorrect instance
            else
            {
                score = points.at(symbol);
                break;
            }
        }
        // adds the symbol to the stack, otherwise
        else
        {
            symbolStack.push(symbol);
        }
        printStack(symbolStack, ' ');
    }

    return score;
}

void printStack(const stack<char> &stackSymbol, const char &curr)
{
    stack<char> tempStack;
    stack<char> secondTempStack = stackSymbol;

    // reverse the stack for printing
    while (!secondTempStack.empty())
    {
        tempStack.push(secondTempStack.top());
        secondTempStack.pop();
    }

    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << curr << endl;
}