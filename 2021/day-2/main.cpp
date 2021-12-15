#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileIn("../sample.txt");

    if (!fileIn)
    {
        return -1;
    }

    int depth = 0;
    int horizontal = 0;

    while (!fileIn.eof())
    {
        string direction;
        int unit;

        fileIn >> direction;
        fileIn >> unit;

        if (direction == "forward")
        {
            horizontal += unit;
        }
        else if (direction == "down")
        {
            depth += unit;
        }
        else
        {
            depth -= unit;
        }
    }
    cout << "Part 1: " << horizontal * depth << endl;

    fileIn.close();
    fileIn.open("../sample.txt");

    int aim = 0;
    horizontal = depth = 0;

    while (!fileIn.eof())
    {
        string direction;
        int unit;

        fileIn >> direction;
        fileIn >> unit;

        if (direction == "forward")
        {
            horizontal += unit;
            depth += (aim * unit);
        }
        else if (direction == "up")
        {
            aim -= unit;
        }
        else if (direction == "down")
        {
            aim += unit;
        }
    }

    cout << "Part 2: " << horizontal * depth << endl;
}