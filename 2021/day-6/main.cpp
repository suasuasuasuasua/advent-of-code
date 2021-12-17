#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "LanternFish.h"

using namespace std;

bool readFile(ifstream &fileIn, const string &fileName);
vector<LanternFish> readDataFromFile(ifstream &fileIn);
map<int, int> lanternFishAfterTime(const vector<LanternFish> &allLanternFish, const int &numDays);

int main()
{
    ifstream fileIn;
    // string fileName = "../sample.txt";
    string fileName = "../input.txt";
    if (!readFile(fileIn, fileName))
    {
        cout << "File could not be read" << endl;
        return -1;
    }

    vector<LanternFish> OGLanternFish = readDataFromFile(fileIn);

    // Part 1: count lanternfish after 80 days
    int numDays = 80;
    auto p1LanternFish = lanternFishAfterTime(OGLanternFish, numDays);

    cout << "Part 1: " << p1LanternFish.size() << endl;
    // Part 2: count lanternfish after 256 days
    numDays = 256;
    auto p2LanternFish = lanternFishAfterTime(OGLanternFish, numDays);

    cout << "Part 2: " << p2LanternFish.size() << endl;
}

bool readFile(ifstream &fileIn, const string &fileName)
{
    fileIn.open(fileName);
    if (!fileIn)
    {
        return false;
    }
    return true;
}

vector<LanternFish> readDataFromFile(ifstream &fileIn)
{
    vector<LanternFish> allLanternFish;
    while (!fileIn.eof())
    {
        int age;
        fileIn >> age;
        if (fileIn.fail())
        {
            fileIn.clear();
            fileIn.ignore();
            continue;
        }
        allLanternFish.push_back(LanternFish(age));
    }
    return allLanternFish;
}

map<int, int> lanternFishAfterTime(const vector<LanternFish> &allLanternFish, const int &numDays)
{
    map<int, int> newLanternFish;

    for (auto &fish : allLanternFish)
    {
        newLanternFish[fish.age]++;
    }

    // TODO Figure out how to carousel the map elements
    // 8<-1<-2<-3<-4<-5<-6<-7<-8
    // 
    // maybe don't use a LanternFish class?
    for (int i = 1; i < numDays; i++)
    {
    }

        return newLanternFish;
}