#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fileIn;
    fileIn.open("../sample.txt");
    if (!fileIn) { return -1; }

    vector<int> depths;

    int temp;
    while (!fileIn.eof()) {         // read in the data from the file
        fileIn >> temp;
        depths.push_back(temp);
    }
    fileIn.close();
    // depths.pop_back();

    int count = 0;

    /* part 1 */ 
    for (int i = 1; i < depths.size(); i++) {   // if the current depth is greater than the depth previous, then increment the count by 1
        if (depths.at(i) > depths.at(i - 1)) {
            count ++;
        }
    }

    cout << "Count: " << count << endl;

    /* part 2 */
    count = 0;

    for (int i = 3; i < depths.size(); i++) {
        int currSum = depths.at(i) + depths.at(i - 1) + depths.at(i - 2);
        int prevSum = depths.at(i - 1) + depths.at(i - 2) + depths.at(i - 3);

        if (currSum > prevSum) {
            count ++;
        }
    }


    cout << "Count: " << count << endl;
}