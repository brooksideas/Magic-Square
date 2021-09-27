#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include "boardType.h"

using namespace std;

boardType::boardType() {}
boardType::boardType(int boardSize)
{

    if (!checkSize(boardSize))
    {
        std::cout << "Error, invalid board size. No board created." << endl;
        // set the size set 0 and board to null
        size = 0;
        //board is NULL by default so no need to set it to NULL here;
    }
    else
    {
        // dynamically allocate memory of size `M × N`
        size = boardSize;
        int M = size;
        const auto N = size;

        // assign values of 0 to the allocated memory matrix
        vector<vector<int>> dynamicBoard(M, vector<int>(N, 0));
        board = dynamicBoard; 
    }
}
boardType::~boardType()
{
    // delete/deallocate Dynamically allocated memory
    board.clear();
}

bool boardType::checkSize(int boardSize)
{

    if (BRD_SIZE_MIN <= boardSize && boardSize <= BRD_SIZE_MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// We can have common validator before get and set
bool boardType::validateBoard(int row, int column)
{
    if (row <= size && column <= size)
    {
        return true;
    }
    else
    {
        cout << "Error, invalid board location." << endl;
        return false;
    }
}

// return the element at the specific location if it is valid location
const int boardType::getCell(int row, int column)
{
    if (validateBoard(row, column))
    {
        cout << "value" << board[row][column];
        return board[row][column];
    }
    return -1;
}

// sets the element at the specific location if it is valid location
void boardType::setCell(int row, int column, int value)
{
    if (validateBoard(row, column))
    {
        board[row][column] = value;
    }
    getCell(row, column);
    printGrid();
}
// Return the Board Size
const int boardType::getOrder()
{

    return size;
}

const void boardType::printGrid()
{
    const char *bold = "\033[1m";
    const char *unbold = "\033[0m";
    cout << bold << "CS 202 - Magic Squares" << endl;

    // print the created array
    int M = size;
    const auto N = size;
    for (int i = 0; i < M; i++)
    {
        cout << "---";
        for (int j = 0; j < N; j++)
        {
            cout << "|   " << board[i][j] << "  |";
        }
        cout << endl;
    }
}