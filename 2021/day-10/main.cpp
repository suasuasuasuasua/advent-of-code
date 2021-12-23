#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void solve();
bool openFile(ifstream &fileIn, const string &fileName);
vector<string> readFile(ifstream &fileIn);

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