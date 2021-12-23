#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int binaryToDecimal(long long binaryNum);
vector<string> parser(vector<string> binaryNums, int j, string type);

int main()
{

    // open file and read in data
    // ifstream fileIn("../sample.txt");
    ifstream fileIn("../input.txt");

    if (!fileIn)
    {
        return -1;
    }

    vector<string> allBits;

    while (!fileIn.eof())
    {
        string temp;
        getline(fileIn, temp);

        allBits.push_back(temp);
    }
    fileIn.close();

    // part 1
    string gammaStr, epsilonStr;

    // iterate through all of the bits
    // note the order, as we traverse down columns, as opposed to across rows
    for (int j = 0; j < allBits.at(0).size(); j++)
    {
        // resets the zero and one counter for each column
        int zero = 0, one = 0;
        for (int i = 0; i < allBits.size(); i++)
        {
            // current bit
            char curr = allBits.at(i).at(j);
            // increment the respective counter based on the bit's value
            if (curr == '0')
            {
                zero++;
            }
            else if (curr == '1')
            {
                one++;
            }
        }

        // for each column, construct the gamma and epsilon strings
        //
        // add the majority to gamma, add the minority to epsilon
        if (zero > one)
        {
            gammaStr += '0';
            epsilonStr += '1';
        }
        else
        {
            gammaStr += '1';
            epsilonStr += '0';
        }
    }

    // cout << "Gamma: " << gammaStr << " Epsilon: " << epsilonStr << endl;

    // converts the string to a long long integer because a normal integer does not have enough bits
    long long gammaBin = stoul(gammaStr);
    long long epsilonBin = stoul(epsilonStr);

    // convert using the user-defined function
    int gamma = binaryToDecimal(gammaBin);
    int epsilon = binaryToDecimal(epsilonBin);

    // cout << "Gamma: " << gamma << " Epsilon: " << epsilon << endl;
    cout << "Part 1: " << gamma * epsilon << endl;

    // part 2

    // open the file again for reading
    fileIn.open("../sample.txt");

    if (!fileIn)
    {
        return -1;
    }

    allBits.clear();
    while (!fileIn.eof())
    {
        string temp;
        getline(fileIn, temp);
        allBits.push_back(temp);
    }

    // may need to look into a function that can treat both oxygen and carbon dioxide at the same time, as opposed to seperately
    // right now, i can't quite imagine how to do that simultaneously without making things very ugly
    vector<string> oxygen = allBits, carbonDioxide = allBits;

    // operate on each column of the data
    for (int j = 0; j < oxygen.at(0).size(); j++)
    {
        // constantly update the oxygen as criteria is met
        oxygen = parser(oxygen, j, "oxygen");

        // once only one entry remains, then exit
        if (oxygen.size() == 1)
        {
            break;
        }
    }
    for (int j = 0; j < carbonDioxide.at(0).size(); j++)
    {
        carbonDioxide = parser(carbonDioxide, j, "co2");

        if (carbonDioxide.size() == 1)
        {
            break;
        }
    }

    // converts to long long
    long long oxyBin = stoul(oxygen.at(0));
    long long co2Bin = stoul(carbonDioxide.at(0));

    // converts to decimal from binary form
    int oxy = binaryToDecimal(oxyBin);
    int co2 = binaryToDecimal(co2Bin);

    // cout << "Oxygen: " << oxyBin << " Carbon Dioxide: " << co2Bin << endl;
    // cout << "Oxygen: " << oxy << " Carbon Dioxide: " << co2 << endl;

    cout << "Part 2: " << oxy * co2 << endl;
}

// converts binary to decimal
int binaryToDecimal(long long binary)
{

    // stores the decimal to be returned
    int decimal = 0;
    // works off of a temporary variable, as we don't want to change the binary
    auto temp = binary;

    // starting from the right side, the base is 1, then exponentially increases
    int base = 1;

    // iterates while temp is not equal to 0
    while (temp)
    {
        // parses the digit farthest to the right
        int lastDigit = temp % 10;
        // removes the digit farthest to the right
        temp = temp / 10;

        // multiples the removed digit by the base to incrementally add to the decimal
        decimal += lastDigit * base;
        // increases the base as we move left
        base *= 2;
    }

    return decimal;
}

vector<string> parser(vector<string> binaryNums, int j, string type)
{

    // the vector that remains after data is parsed
    vector<string> parsed;

    // counter for zeros and ones
    int zero = 0, one = 0;
    // keeps track of the indices of the rows for zeros and ones
    vector<int> izeros, iones;

    // iterates down the column
    // everything is the same here, except that we add the row index
    for (int i = 0; i < binaryNums.size(); i++)
    {
        auto curr = binaryNums.at(i).at(j);

        if (curr == '0')
        {
            zero++;
            izeros.push_back(i);
        }
        else
        {
            one++;
            iones.push_back(i);
        }
    }

    // for oxygen, always keep the majority rows, else the rows with 1
    if (type == "oxygen")
    {
        if (zero > one)
        {
            for (auto num : izeros)
            {
                parsed.push_back(binaryNums.at(num));
            }
        }
        else if (one > zero)
        {
            for (auto num : iones)
            {
                parsed.push_back(binaryNums.at(num));
            }
        }
        else
        {
            for (auto num : iones)
            {
                parsed.push_back(binaryNums.at(num));
            }
        }

        // for co2, always keep the minority rows, else the rows with 0
    }
    else if (type == "co2")
    {
        if (zero < one)
        {
            for (auto num : izeros)
            {
                parsed.push_back(binaryNums.at(num));
            }
        }
        else if (one < zero)
        {
            for (auto num : iones)
            {
                parsed.push_back(binaryNums.at(num));
            }
        }
        else
        {
            for (auto num : izeros)
            {
                parsed.push_back(binaryNums.at(num));
            }
        }
    }
    return parsed;
}