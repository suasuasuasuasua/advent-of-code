#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

bool readFile(ifstream &fileIn, const string &fileName);
vector<int> readDataFromFile(ifstream &fileIn);
map<int, unsigned long long int> lanternFishAfterTime(const vector<int> &allLanternFish, const int &numDays);

int main()
{
    ifstream fileIn;
    string fileName = "../sample.txt";
    // string fileName = "../input.txt";
    if (!readFile(fileIn, fileName))
    {
        cout << "File could not be read" << endl;
        return -1;
    }

    vector<int> OGLanternFishAges = readDataFromFile(fileIn);

    // Part 1: count lanternfish after 80 days
    int numDays = 80;
    auto p1LanternFish = lanternFishAfterTime(OGLanternFishAges, numDays);
    unsigned long long int partOneSum = 0;
    for (const auto &ageGroup : p1LanternFish)
    {
        partOneSum += ageGroup.second;
    }
    cout << "Part 1: " << partOneSum << endl;

    // Part 2: count lanternfish after 256 days
    numDays = 256;
    auto p2LanternFish = lanternFishAfterTime(OGLanternFishAges, numDays);
    unsigned long long int partTwoSum = 0;
    for (const auto &ageGroup : p2LanternFish)
    {
        partTwoSum += ageGroup.second;
    }
    cout << "Part 2: " << partTwoSum << endl;
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

vector<int> readDataFromFile(ifstream &fileIn)
{
    vector<int> lanternFishAges;
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
        lanternFishAges.push_back(age);
    }
    return lanternFishAges;
}

// note: remember to use long long int because these puzzles generally require huge numbers
map<int, unsigned long long int> lanternFishAfterTime(const vector<int> &allLanternFish, const int &numDays)
{
    map<int, unsigned long long int> fishAgeGroup;

    for (const auto &fish : allLanternFish)
    {
        fishAgeGroup[fish]++;
    }

    // Carousel the map elements
    // 8<-1<-2<-3<-4<-5<-6<-7<-8
    //
    for (int i = 0; i < numDays; i++)
    {
        unsigned long long int ageZero = fishAgeGroup[0];
        for (int j = 1; j <= 8; j++)
        {
            fishAgeGroup[j - 1] = fishAgeGroup[j];
            if (j == 8)
            {
                fishAgeGroup[j] = 0;
            }
        }
        fishAgeGroup[6] += ageZero;
        fishAgeGroup[8] = ageZero;
    }
    return fishAgeGroup;
}