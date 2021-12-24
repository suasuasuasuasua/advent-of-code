#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

void solve();
bool openFile(ifstream &fileIn, const string &fileName);
vector<string> readFile(ifstream &fileIn);
long long int checkChunk(const string &chunk, const int &part);
void printStack(const stack<char> &missingStackSymbols, const char &curr);
void copyOppositeStack(const stack<char> &originalStack, stack<char> &copyStack);
long long int missingStackPoints(const stack<char> &missingStackSymbols);

map<char, char> parens = {{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};
map<char, char> oppositeParens = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
map<char, int> partOnePoints = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
map<char, int> partTwoPoints = {{')', 1}, {']', 2}, {'}', 3}, {'>', 4}};

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
        cout << "File could not be opened for reading" << endl;
        return;
    }

    vector<string> fileData = readFile(fileIn);

    // part 1
    long long int partOne = 0;
    for (const auto &line : fileData)
    {
        partOne += checkChunk(line, 1);
    }
    cout << "Part 1: " << partOne << endl;

    // part 2
    long long int partTwo = 0;
    set<long long int> partTwoLines;
    for (const auto &line : fileData)
    {
        long long int sum = checkChunk(line, 2);
        if (sum != 0)
        {
            partTwoLines.insert(sum);
        }
    }
    auto iter = partTwoLines.begin();
    advance(iter, partTwoLines.size() / 2);

    partTwo = *iter;

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

long long int checkChunk(const string &chunk, const int &part)
{
    long long int score = 0;
    stack<char> symbolStack;

    for (const auto &symbol : chunk)
    {
        // if the current symbol is closing
        if (parens.count(symbol))
        {
            // stop at the first incorrect instance AND if we are solving the first part
            if (symbolStack.top() != parens.at(symbol))
            {
                if (part == 1)
                {
                    score = partOnePoints.at(symbol);
                    return score;
                }
                else
                {
                    return score;
                }
            }
            // else if the previous symbol is equal to the closing symbol's corresponding opening
            // i.e. '}' to '{'
            // remove the previous symbol and don't add the current symbol because they matched
            else
            {
                symbolStack.pop();
            }
        }
        // adds the symbol to the stack, otherwise
        else
        {
            symbolStack.push(symbol);
        }
        // printStack(symbolStack, ' ');
    }

    // for the second part, we'll operate on the remaining, incomplete stack
    if (part == 2)
    {
        stack<char> missingSymbols;
        copyOppositeStack(symbolStack, missingSymbols);

        score = missingStackPoints(missingSymbols);
    }
    return score;
}

void printStack(const stack<char> &missingStackSymbols, const char &curr)
{
    stack<char> tempStack;
    stack<char> secondTempStack = missingStackSymbols;

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
}

void copyOppositeStack(const stack<char> &originalStack, stack<char> &copyStack)
{
    stack<char> tempStack;
    stack<char> secondTempStack = originalStack;

    while (!secondTempStack.empty())
    {
        auto current = secondTempStack.top();
        auto oppositeCurrent = oppositeParens.at(current);

        tempStack.push(oppositeCurrent);
        secondTempStack.pop();
    }
    while (!tempStack.empty())
    {
        auto current = tempStack.top();
        copyStack.push(current);
        tempStack.pop();
    }
}

long long int missingStackPoints(const stack<char> &missingStackSymbols)
{
    long long int sum = 0;
    auto tempStack = missingStackSymbols;
    while (!tempStack.empty())
    {
        auto currentSymbol = tempStack.top();
        int pointValue = partTwoPoints.at(currentSymbol);

        sum *= 5;
        sum += pointValue;

        tempStack.pop();
    }
    return sum;
}