#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void mark(vector<vector<int>> &board, int &num);
int sumUnmarked(const vector<vector<int>> &board);
bool isWin(vector<vector<int>> board);
void print(const vector<vector<int>> &board);

// tracks the points that have been marked
// uses i and j in place of x and y
class Point
{
public:
    Point(int i, int j) : i(i), j(j) {}
    int i, j;
    bool isAdjacent(Point point) { return false; }
    void print() { cout << i << " " << j << endl; }

    int geti() { return i; }
    int getj() { return j; }
};

bool winHori(vector<Point> &marked);
bool winVert(vector<Point> &marked);
bool winRightDiag(vector<Point> &marked);
bool winLeftDiag(vector<Point> &marked);

#define winningSet    \
    {                 \
        0, 1, 2, 3, 4 \
    }

int main()
{
    // read in the file
    ifstream fileIn("sample.txt");
    // ifstream fileIn("test.txt");
    // ifstream fileIn("horizontal.txt");
    // ifstream fileIn("vertical.txt");
    // ifstream fileIn("right-diagonal.txt");
    // ifstream fileIn("left-diagonal.txt");
    if (!fileIn)
    {
        return -1;
    }

    // get first line of input file for bingo numbers
    string bingoLine;
    getline(fileIn, bingoLine);

    // turn all commas to spaces to parse
    for (int i = 0; i < bingoLine.size(); i++)
    {
        if (bingoLine.at(i) == ',')
        {
            bingoLine.at(i) = ' ';
        }
    }

    stringstream ss;
    ss << bingoLine;

    // vector of bingo numbers
    vector<int> bingoNumbers;
    // temporary variables
    string tempStr;
    int tempInt;
    // iterate through all bingo numbers with stringstream
    while (!ss.eof())
    {
        // pass one word to the temp string
        ss >> tempStr;
        // if stringstream can convert to integer, then add to vector
        if (stringstream(tempStr) >> tempInt)
        {
            bingoNumbers.push_back(tempInt);
        }
    }

    // store the rest of the numbers
    // vector of two dimensional boards
    vector<vector<vector<int>>> allBoards;

    while (!fileIn.eof())
    {
        // a single board contains is two dimensional
        vector<vector<int>> board;
        for (int i = 0; i < 5; i++)
        {
            // singular line of the board
            vector<int> boardLine;
            for (int j = 0; j < 5; j++)
            {
                int temp;
                fileIn >> temp;
                boardLine.push_back(temp);
            }
            board.push_back(boardLine);
        }
        allBoards.push_back(board);
    }

    // play the game

    // iterates over the list of bingo numbers
    for (auto num : bingoNumbers)
    {
        // check each board with each number
        for (auto &board : allBoards)
        {
            // marks each board, if applicable
            mark(board, num);
            // print(board);

            // checks the win-condition on each board
            if (isWin(board))
            {
                // multiply current num against sum of non-marked
                int unmarked = sumUnmarked(board);
                cout << "Part 1: " << unmarked * num << endl;
                return 0;
            }
        }
    }
}

// marks board based on given bingo number
void mark(vector<vector<int>> &board, int &num)
{
    // looks through each number on the board
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.at(i).size(); j++)
        {
            int curr = board.at(i).at(j);
            if (curr == num)
            {
                // marks found numbers as -1, as this is not a normal number
                board.at(i).at(j) = -1;
                return;
            }
        }
    }
}
// checks if the player has won by tallying which checking which points have been marked
bool isWin(vector<vector<int>> board)
{
    vector<Point> marked;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.at(i).size(); j++)
        {
            int curr = board.at(i).at(j);
            // marked points are denoted with a -1
            if (curr == -1)
            {
                Point temp(i, j);
                marked.push_back(temp);
            }
        }
    }
    // don't check points until there are at least 5 marked
    if (marked.size() < 5)
    {
        return false;
    }

    // check all possible win conditions
    if (winHori(marked) || winVert(marked) || winRightDiag(marked) || winLeftDiag(marked))
    {
        return true;
    }
    // else the board has not won yet
    return false;
}

// if the a board passed a win condition, then sum up the points that are not marked
int sumUnmarked(const vector<vector<int>> &board)
{
    int sum = 0;
    for (auto &line : board)
    {
        for (auto &num : line)
        {
            if (num != -1)
            {
                sum += num;
            }
        }
    }
    return sum;
}

// prints the board to keep track
void print(const vector<vector<int>> &board)
{
    for (auto &line : board)
    {
        for (auto &num : line)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

// horizontal win condition means (i,0), (i,0), ...
// we want to check if all marked points are on the same row
bool winHori(vector<Point> &marked)
{

    // iterates for each row of the board
    for (int i = 0; i < 5; i++)
    {
        int count = 0;
        // checks marked point
        for (auto &point : marked)
        {
            int tempi = point.geti();
            // increment the count if the marked point has the same value as the i
            if (i == tempi)
            {
                count++;
            }
        }
        // if we count 5, then there must have been 5 marked points horizontally
        if (count == 5)
        {
            // cout << "Horizontal" << endl;
            return true;
        }
    }
    return false;
}
// same as horizontal, except that we check the j instead, such that all marked points are in the same column
bool winVert(vector<Point> &marked)
{

    for (int j = 0; j < 5; j++)
    {
        int count = 0;
        for (auto &point : marked)
        {
            int tempj = point.getj();
            if (j == tempj)
            {
                count++;
            }
        }
        if (count == 5)
        {
            // cout << "Vertical" << endl;
            return true;
        }
    }
    return false;
}

// the right diagonal win condition is where all marked points have the same value
bool winRightDiag(vector<Point> &marked)
{

    for (auto &point : marked)
    {
        int tempi = point.geti();
        int tempj = point.getj();
        if (tempi != tempj)
        {
            return false;
        }
    }
    // cout << "Right Diagonal" << endl;
    return true;
}

// for left diagonal win condition is where all marked points add up to 4
bool winLeftDiag(vector<Point> &marked)
{
    for (auto &point : marked) {
        int tempi = point.geti();
        int tempj = point.getj();
        int test = tempi + tempj;
        if (test != 4)
        {
            return false;
        }
    }
    cout << "Left Diagonal" << endl;
    return true;
}