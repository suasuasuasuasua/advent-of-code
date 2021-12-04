#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fileIn("sample.txt");

    if (!fileIn) {
        return -1;
    }

    int depth = 0;
    int horizontal = 0;
    int aim = 0;

    while (!fileIn.eof()) {
        string direction;
        int unit;

        fileIn >> direction;
        fileIn >> unit;

        if (direction == "forward") {
            horizontal += unit;
            depth += (aim * unit);
        }
        else if (direction == "up") {
            aim -= unit;
        }
        else if (direction == "down") {
            aim += unit;
        }
    }

    cout << horizontal * depth << endl;
}

// #include <map>

//     string direction;
//     int units;
//     fileIn >> direction;
//     fileIn >> units;

//     instructions[direction].push_back(units);
// }

// // part 1

// int horiz = 0, depth = 0;

// for (auto instr : instructions) {
//     auto dir = instr.first;
//     auto units = instr.second;

//     if (dir == "forward") {
//         for (auto unit : units) {
//             horiz += unit;
//         }
//     }
//     if (dir == "up") {
//         for (auto unit : units) {
//             depth -= unit;
//         }
//     }
//     if (dir == "down") {
//         for (auto unit : units) {
//             depth += unit;
//         }
//     }
// }

// cout << "Part 1: " << horiz * depth << endl;

// // part 2
// int aim = 0;
// horiz = 0;
// depth = 0;

// for (auto instr : instructions) {
//     auto dir = instr.first;
//     auto units = instr.second;

//     if (dir == "forward") {
//         for (auto unit : units) {
//             horiz += unit;
//             depth += (aim * unit);
//             cout << horiz << " " << depth << endl;
//         }
//     }
//     if (dir == "up") {
//         for (auto unit : units) {
//             depth -= unit;
//             aim -= unit;
//         }
//     }
//     if (dir == "down") {
//         for (auto unit : units) {
//             depth += unit;
//             aim += unit;
//         }
//     }
// }

// cout << "Part 2: " << horiz * depth << endl;