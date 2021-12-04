#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int binaryToDecimal(long long binaryNum);
vector<string> parser(vector<string> binaryNums, int j, string type);

int main() {

    // open file and read in data    

    ifstream fileIn("sample.txt");
    // ifstream fileIn("test.txt");

    if (!fileIn) {
        return -1;
    }

    vector<string> allBits;

    while (!fileIn.eof()) {
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
                one ++;
            }
        }

        // for each column, construct the gamma and epsilon strings
        // 
        // add the majority to gamma, add the minority to epsilon
        if (zero > one) {
            gammaStr   += '0';
            epsilonStr += '1';
        }
        else {
            gammaStr   += '1';
            epsilonStr += '0';
        }
    }

    cout << "Gamma: " << gammaStr << " Epsilon: " << epsilonStr << endl;

    // converts the string to a long long integer because a normal integer does not have enough bits
    long long gammaBin = stoul(gammaStr);
    long long epsilonBin = stoul(epsilonStr);

    // convert using the user-defined function
    int gamma = binaryToDecimal(gammaBin);
    int epsilon = binaryToDecimal(epsilonBin);

    cout << "Gamma: " << gamma << " Epsilon: " << epsilon << endl;
    cout << "Part 1: " << gamma * epsilon << endl;

    // part 2

    // open the file again for reading
    fileIn.open("sample.txt");
    // fileIn.open("test.txt");

    if (!fileIn) {
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
    vector<string> oxygen = allBits, carbonDioxide = allBits;

    // for each column in the oxygen data, parse it based on the function
    for (int j = 0; j < oxygen.at(0).size(); j++) {
        oxygen = parser(oxygen, j, "oxygen");
        
        // once only one entry remains, then exit
        if (oxygen.size() == 1) {
            break;
        }
    }
    for (int j = 0; j < carbonDioxide.at(0).size(); j++) {
        carbonDioxide = parser(carbonDioxide, j, "co2");
        
        if (carbonDioxide .size() == 1) {
            break;
        }
    }

    long long oxyBin = stoul(oxygen.at(0));
    long long co2Bin = stoul(carbonDioxide.at(0));

    int oxy = binaryToDecimal(oxyBin);
    int co2 = binaryToDecimal(co2Bin);

    cout << "Oxygen: " << oxyBin << " Carbon Dioxide: " << co2Bin << endl;
    cout << "Oxygen: " << oxy << " Carbon Dioxide: " << co2 << endl;


    cout << "Part 2: " << oxy * co2 << endl;
}

// converts binary to decimal
int binaryToDecimal(long long binary) {

    int decimal = 0;
    auto temp = binary;

    int base = 1;

    while (temp) {
        int lastDigit = temp % 10;
        temp = temp / 10;

        decimal += lastDigit * base;
        base *= 2;
    }

    return decimal;
}

vector<string> parser(vector<string> binaryNums, int j, string type) {

    vector<string> parsed;

    int zero = 0, one = 0;
    vector<int> izeros, iones;

    for (int i = 0; i < binaryNums.size(); i++)
    {
        auto curr = binaryNums.at(i).at(j);

        if (curr == '0') {
            zero++;
            izeros.push_back(i);
        }
        else
        {
            one++;
            iones.push_back(i);
        }
    }

    if (type == "oxygen") {
        if (zero > one) {
            for (auto num : izeros) {
                parsed.push_back(binaryNums.at(num));
            }
        } else if (one > zero) {
            for (auto num : iones) {
                parsed.push_back(binaryNums.at(num));
            }
        } else {
                for (auto num : iones) {
                    parsed.push_back(binaryNums.at(num));
                }
        }

    } else if (type == "co2") {
        if (zero < one) {
            for (auto num : izeros) {
                parsed.push_back(binaryNums.at(num));
            }
        } else if (one < zero) {
            for (auto num : iones) {
                parsed.push_back(binaryNums.at(num));
            }
        } else {
                for (auto num : izeros) {
                    parsed.push_back(binaryNums.at(num));
                }
        }
    }
    return parsed;
}