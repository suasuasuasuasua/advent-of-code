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
void printStack(const stack<char> &missingStackSymbols);
void copyOppositeStack(const stack<char> &originalStack, stack<char> &copyStack);
long long int missingStackPoints(const stack<char> &missingStackSymbols);
long long int getMiddleOfSet(const set<long long int> &s);

map<char, char> closingToOpeningParens = {{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};
map<char, char> openingToClosingParens = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};
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
    // sum each line for the point value
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
        // if the sum is non-zero, i.e. the line was incomplete, then insert it into the set
        if (sum)
        {
            partTwoLines.insert(sum);
        }
        // else if the line was corrupted, i.e. incorrect, then don't consider it
    }

    // get the median value of the set
    partTwo = getMiddleOfSet(partTwoLines);

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
        if (closingToOpeningParens.count(symbol))
        {
            // stop at the first incorrect instance AND if we are solving the first part
            if (symbolStack.top() != closingToOpeningParens.at(symbol))
            {
                if (part == 1)
                {
                    // use the current symbol (the one that was incorrect) as a key to get the point value
                    score = partOnePoints.at(symbol);
                }
                return score;
            }
            // else if the previous symbol is equal to the closing symbol's corresponding opening
            // i.e. '}' to '{'
            // remove the previous symbol and don't add the current symbol because they matched
            // this begins to clear the stack
            else
            {
                symbolStack.pop();
            }
        }
        // adds the symbol to the stack if it is not closing
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

void printStack(const stack<char> &missingStackSymbols)
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

    // change all opening symbols to the corresponding closing symbol
    while (!secondTempStack.empty())
    {
        // here the current are all going to be opening parens
        auto current = secondTempStack.top();
        // use the current as the key for the map to get the opposite
        auto oppositeOfCurrent = openingToClosingParens.at(current);

        tempStack.push(oppositeOfCurrent);
        secondTempStack.pop();
    }
    // unreverse the stack
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
        auto current = tempStack.top();
        // use the current symbol as a key for the map to get the point value
        int pointValue = partTwoPoints.at(current);

        sum *= 5;
        sum += pointValue;

        tempStack.pop();
    }
    return sum;
}

long long int getMiddleOfSet(const set<long long int> &s)
{
    auto iter = s.begin();
    advance(iter, s.size() / 2);
    return *iter;
}