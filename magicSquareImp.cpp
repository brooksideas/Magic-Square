#include <iostream>
#include <string.h>
#include <string>
#include "boardType.h"
#include "magicSquareType.h"

using namespace std;

magicSquareType::magicSquareType() {}
magicSquareType::~magicSquareType() {}

magicSquareType::magicSquareType(int boardSize, std::string boardTitle)
{
    title = boardTitle;
    boardType boardTypeObject;

    //boardType boardTypeObject(boardSize);
    // magicNumber();
    // validateMagicSquare();
}
// magicNumber =  size * size (board size squared) plus 1 divided by 2
// then multiply the above value by the size follows BODMAS rule

int magicSquareType::magicNumber() const
{
    boardType boardTypeObject;
    int magicNumber, boardSize;
    boardSize = boardTypeObject.getOrder();
    boardSize = boardSize * boardSize; // board size squared
    boardSize = boardSize + 1;         // add 1 to it
    magicNumber = boardSize * 2;       // multiply the entire value by 2
    return magicNumber;
}

bool magicSquareType::validateMagicSquare() const
{
    boardType boardTypeObject;
    int boardSize = boardTypeObject.getOrder();
    int columnSumHolder[boardSize];
    // go through the matrix and add all the element along the row
    // at the same time when going to a new row add all the columns and store it as
    // columnSumHolder[currentRowIndex] which we will compare once the row addition is completed

    for (int i = 0; i < boardSize; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < boardSize; j++)
        {
            rowSum = rowSum + boardTypeObject.getCell(i, j);
            columnSumHolder[j] = boardTypeObject.getCell(i, j) + columnSumHolder[j];
        }
        // if row level additions are not equal to the magic number return false
        if (rowSum != magicNumber())
        {
            return false;
        }
    }

    // check all the added columns values are equal to the magicNumber
    for (int k = 0; k < boardSize; k++)
    {
        if (columnSumHolder[k] != magicNumber())
        {
            return false;
        }
    }

    // if column and rows are correct the Main diagonals are correct based on the Theory, so return true
    return true;
}
