#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include "boardType.h"

using namespace std;

boardType::boardType() {}

int globalBoardSize; // use this for easy access of the protected variable
vector<vector<int>> globalDynamicBoard(globalBoardSize, vector<int>(globalBoardSize, 0));

boardType::boardType(int boardSize)
{

    if (!checkSize(boardSize))
    {
        std::cout << "Error, invalid board size. No board created." << endl;
        // set the size set 0 and board to null
        size = 0;
        globalBoardSize = size;
        //board is NULL by default so no need to set it to NULL here;
        // EXIT_FAILURE
        exit(1);
    }
    else
    {
        // dynamically allocate memory of size `M × N`
        size = boardSize;
        globalBoardSize = boardSize;
        int M = globalBoardSize;
        const auto N = globalBoardSize;

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
int boardType::validateBoard(int row, int column)
{
    if (row <= globalBoardSize && column <= globalBoardSize)
    {
        return 1;
    }
    else
    {
        cout << "Error, invalid board location." << endl;
        return 0;
    }
}

// return the element at the specific location if it is valid location
int boardType::getCell(int row, int column)
{

    if (validateBoard(row, column) == 1)
    {
        return globalDynamicBoard[row][column];
    }
    else
    {
        return -1;
    }
}

// sets the element at the specific location if it is valid location
void boardType::setCell(int row, int column, int value)
{
    board.resize(globalBoardSize);
    if (validateBoard(row, column))
    {
        board[row][column] = value;
    }

   // update our globalDynamicBoard for easy access
    if (row == globalBoardSize && column == globalBoardSize)
    {
        globalDynamicBoard = board; 
    }
}
// Return the Board Size
int boardType::getOrder() const
{

    return globalBoardSize;
}
vector<vector<int>> boardType::getBoard()
{
    return globalDynamicBoard;
}

void boardType::printGrid() const
{
    const char *bold = "\033[1m";
    const char *unbold = "\033[0m";
    cout << bold << "CS 202 - Magic Squares" << endl; 
    cout << " Magic Square, order: " << getOrder() << endl; 

    // print the created array
    int M = globalBoardSize;
    const auto N = globalBoardSize;
    for (int i = 0; i < M; i++)
    {
        cout << "---";
        for (int j = 0; j < N; j++)
        {
            cout << "|   " << globalDynamicBoard[i][j] << "  |";
        }
        cout << endl;
    }
}