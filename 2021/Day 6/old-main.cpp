/*
 * this version creates a vector that is simply too big to manage
 */
#include <iostream>
#include <fstream>
#include <vector>

#include "LanternFish.h"

using namespace std;

bool readFile(ifstream &fileIn, const string &fileName);
vector<LanternFish> readDataFromFile(ifstream &fileIn);
vector<LanternFish> lanternFishAfterTime(const vector<LanternFish> &allLanternFish, const int &numDays);

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

vector<LanternFish> lanternFishAfterTime(const vector<LanternFish> &allLanternFish, const int &numDays)
{
    vector<LanternFish> newLanternFish;
    for (const auto &fish : allLanternFish)
    {
        newLanternFish.push_back(fish);
    }

    for (int i = 1; i <= numDays; i++)
    {
        vector<LanternFish> fishToBeAdded;
        for (auto &fish : newLanternFish)
        {
            fish.dayPass();
            if (fish.age < 0)
            {
                auto newFish = fish.spawnNew();
                fish.resetAge();
                fishToBeAdded.push_back(newFish);
            }
        }

        for (const auto &newFish : fishToBeAdded)
        {
            newLanternFish.push_back(newFish);
        }
        cout << "Day " << i << ":    ";
        // for (auto &fish : newLanternFish)
        // {
        //     fish.print();
        // }
        cout << endl;
    }
    return newLanternFish;
}