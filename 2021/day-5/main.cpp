#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// print function for map
void print(const vector<vector<int>> &map)
{
    for (auto &line : map)
    {
        for (auto &num : line)
        {
            cout << " " << num;
        }
        cout << endl;
    }
}

int main()
{
    // read in the file
    // ifstream fileIn("sample.txt");
    // ifstream fileIn("test.txt");
    ifstream fileIn("test2.txt");
    if (!fileIn)
    {
        return -1;
    }

    // reads in the lines from the file
    stringstream ss;

    // stores all points that we will be reading in
    // { (x1,y1,x2,y2), ... } in this format
    vector<vector<int>> allPoints;
    // tracks the largest x and y to construct the matrix
    int largestX = -1, largestY = -1;

    // reads in all data from the file
    while (!fileIn.eof())
    {
        string temp;
        getline(fileIn, temp);
        vector<int> points;

        // parses each line for non numeric characters, replacing them with spaces
        for (int i = 0; i < temp.size(); i++)
        {
            char curr = temp.at(i);
            if (!isdigit(curr))
            {
                temp.at(i) = ' ';
            }
        }

        // uses a stringstream to parse further into integers
        // first takes in entire string from the temporary string
        ss << temp;
        int x1, y1, x2, y2;

        // parses singular word from stringstream, then converts to integer with function
        // we know that the input file will always have four numbers
        ss >> temp;
        stringstream(temp) >> x1;
        ss >> temp;
        stringstream(temp) >> y1;
        ss >> temp;
        stringstream(temp) >> x2;
        ss >> temp;
        stringstream(temp) >> y2;

        // attempts to find the largest x or y
        if (x1 >= largestX)
        {
            largestX = x1;
        }
        if (x2 >= largestX)
        {
            largestX = x2;
        }
        if (y1 >= largestY)
        {
            largestY = y1;
        }
        if (y2 >= largestY)
        {
            largestY = y2;
        }

        // only adds points that are in a line
        if (x1 == x2 || y1 == y2 || (x1 == y1 && x2 == y2) || (x1 + y1 == x2 + y2))
        {
            points.push_back(x1);
            points.push_back(y1);
            points.push_back(x2);
            points.push_back(y2);
        }

        // clears the stringstream so that it can read again
        ss.clear();
        // sometimes the points vectors will be empty because the points may not necessarily be in a line
        // only add the points that are in a line
        if (!points.empty())
        {
            allPoints.push_back(points);
        }
    }
    fileIn.close();

    // for (auto &line : allPoints)
    // {
    //     for (auto &num : line)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // map holds the matrix that we will be analyzing
    vector<vector<int>> map;
    // constructs the matrix based on the largest X and largest Y
    // note the <= here because we want to be able to index the largest X or largest Y

    // part 1

    for (int i = 0; i <= largestX; i++)
    {
        vector<int> line;
        for (int j = 0; j <= largestY; j++)
        {
            line.push_back(0);
        }
        map.push_back(line);
    }

    // cout << largestX << " " << largestY << endl;

    // iterates over all points that we parsed
    for (int i = 0; i < allPoints.size(); i++)
    {
        // x1, y1, x2, y2 will always be in the positions 0, 1, 2, 3
        int x1, y1, x2, y2;
        // x1 = allPoints.at(i).at(0);
        // y1 = allPoints.at(i).at(1);
        // x2 = allPoints.at(i).at(2);
        // y2 = allPoints.at(i).at(3);

        // supposed to flip the x and y because they are opposite in this context
        // (0,9)->(5,9) means row 9, column 0, instead of row 0, column 9
        // everything still works out
        y1 = allPoints.at(i).at(0);
        x1 = allPoints.at(i).at(1);
        y2 = allPoints.at(i).at(2);
        x2 = allPoints.at(i).at(3);

        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        // if the points are in the same row
        if (x1 == x2)
        {
            // check which yi is bigger than the other to iterate
            if (y1 < y2)
            {
                for (int j = y1; j <= y2; j++)
                {
                    map.at(x1).at(j)++;
                }
            }
            else
            {
                for (int j = y2; j <= y1; j++)
                {
                    map.at(x1).at(j)++;
                }
            }
        }
        // if the points are in the same column
        if (y1 == y2)
        {
            // check which xi is bigger than the other to iterate
            if (x1 < x2)
            {
                for (int j = x1; j <= x2; j++)
                {
                    map.at(j).at(y1)++;
                }
            }
            else
            {
                for (int j = x2; j <= x1; j++)
                {
                    map.at(j).at(y1)++;
                }
            }
        }

        // print(map);
    }

    int count = 0;
    // iterates over the map to see which points have overlap, i.e. which ones are greater than 2
    for (auto &line : map)
    {
        for (auto &num : line)
        {
            if (num >= 2)
            {
                count++;
            }
        }
    }

    // print(map);
    cout << "Part 1: " << count << endl;

    // part 2
    map.clear();
    for (int i = 0; i <= largestX; i++)
    {
        vector<int> line;
        for (int j = 0; j <= largestY; j++)
        {
            line.push_back(0);
        }
        map.push_back(line);
    }

    // iterates over all points that we parsed
    for (int i = 0; i < allPoints.size(); i++)
    {
        // x1, y1, x2, y2 will always be in the positions 0, 1, 2, 3
        int x1, y1, x2, y2;

        y1 = allPoints.at(i).at(0);
        x1 = allPoints.at(i).at(1);
        y2 = allPoints.at(i).at(2);
        x2 = allPoints.at(i).at(3);

        // if the points are in the same row
        if (x1 == x2)
        {
            // check which yi is bigger than the other to iterate
            if (y1 < y2)
            {
                for (int j = y1; j <= y2; j++)
                {
                    map.at(x1).at(j)++;
                }
            }
            else
            {
                for (int j = y2; j <= y1; j++)
                {
                    map.at(x1).at(j)++;
                }
            }
        }
        // if the points are in the same column
        if (y1 == y2)
        {
            // check which xi is bigger than the other to iterate
            if (x1 < x2)
            {
                for (int j = x1; j <= x2; j++)
                {
                    map.at(j).at(y1)++;
                }
            }
            else
            {
                for (int j = x2; j <= x1; j++)
                {
                    map.at(j).at(y1)++;
                }
            }
        }

        // right diagonal
        if (x1 == y1 && x2 == y2)
        {
            if (x1 < x2)
            {
                for (int j = x1; j <= x2; j++)
                {
                    map.at(j).at(j)++;
                }
            }
            if (x2 < x1)
            {
                for (int j = x2; j <= x1; j++)
                {
                    map.at(j).at(j)++;
                }
            }
            // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            // // print(map);
            // cout << "--" << endl;

            // print(map);
        }
        // left diagonal
        if (x1 + y1 == x2 + y2)
        {

            // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

            if (x1 < x2)
            {
                    // 6,10 -> 9,7
                    // 9,7 -> 6,10
                for (int j = x1; j <= x2; j++)
                {
                    int offset = x2 - j;
                    cout << j << " " << x1 << " " << offset << endl;
                    map.at(j).at(offset)++;
                }
            }
            if (x2 < x1)
            {
                // 10,6 -> 9,7
                for (int j = x2; j <= x1; j++)
                {
                    int offset = x1 - j;
                    cout << j << " " << x2 << " " << offset << endl;
                    map.at(j).at(offset)++;
                }
            }
        }
    }

    count = 0;
    // iterates over the map to see which points have overlap, i.e. which ones are greater than 2
    for (auto &line : map)
    {
        for (auto &num : line)
        {
            if (num >= 2)
            {
                count++;
            }
        }
    }
    print(map);
    cout << "Part 2: " << count << endl;
}