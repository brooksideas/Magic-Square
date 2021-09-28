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
    setTitle(boardTitle);
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

// get the title set
string magicSquareType::getTitle() const
{
    return title;
}

void magicSquareType::setTitle(string currentTitle)
{
    title = currentTitle;
}

void magicSquareType::clearMagicSquare()
{
    // dynamically allocate memory of size `M × N`
    int M = size;
    const auto N = size;
    // assign values of 0 to the allocated memory matrix for boardType board value
    vector<vector<int>> dynamicBoard(M, vector<int>(N, 0));
    board = dynamicBoard;
    title = "";
}

void magicSquareType::readMagicSquare()
{
    // check it title is empty and prompt user to enter title
    if (title == "")
    {
        string title;
        cout << "Enter  the title of the Magic Square."
             << endl;
        cin >> title;

        setTitle(title);
    }

    // read magic square using boardType getCell
    int M = size;
    const auto N = size;
    for (int i = 0; i < M; i++)
    {

        for (int j = 0; j < N; j++)
        {
            // cout << "|   " << board[i][j] << "  |";
            getCell(i, j);
        }
    }
}

// printGrid using the base class boardType
void magicSquareType::printMagicSquare() const
{
    boardType boardTypeObject;
    boardTypeObject.printGrid();
}

void OddMagicSquare(vector<vector<int>> &matrix, int boardSize)
{
    int nsqr = boardSize * boardSize;
    int i = 0, j = boardSize / 2; // start position

    for (int k = 1; k <= nsqr; ++k)
    {
        matrix[i][j] = k;

        i--;
        j++;

        if (k % boardSize == 0)
        {
            i += 2;
            --j;
        }
        else
        {
            if (j == boardSize)
                j -= boardSize;
            else if (i < 0)
                i += boardSize;
        }
    }
}

// Doubly Even magic square

void DoublyEvenMagicSquare(vector<vector<int>> &matrix, int boardSize)
{
    vector<vector<int>> I(boardSize, vector<int>(boardSize, 0));
    vector<vector<int>> J(boardSize, vector<int>(boardSize, 0));

    int i, j;

    //prepare I, J
    int index = 1;
    for (i = 0; i < boardSize; i++)
        for (j = 0; j < boardSize; j++)
        {
            I[i][j] = ((i + 1) % 4) / 2;
            J[j][i] = ((i + 1) % 4) / 2;
            matrix[i][j] = index;
            index++;
        }

    for (i = 0; i < boardSize; i++)
        for (j = 0; j < boardSize; j++)
        {
            if (I[i][j] == J[i][j])
                matrix[i][j] = boardSize * boardSize + 1 - matrix[i][j];
        }
}

// singly Even magic square
void SinglyEvenMagicSquare(vector<vector<int>> &matrix, int boardSize)
{
    int p = boardSize / 2;

    vector<vector<int>> M(p, vector<int>(p, 0));
    //MagicSquare(M, p);

    int i, j, k;

    for (i = 0; i < p; i++)
        for (j = 0; j < p; j++)
        {
            matrix[i][j] = M[i][j];
            matrix[i + p][j] = M[i][j] + 3 * p * p;
            matrix[i][j + p] = M[i][j] + 2 * p * p;
            matrix[i + p][j + p] = M[i][j] + p * p;
        }

    if (boardSize == 2)
        return;

    vector<int> I(p, 0);
    vector<int> J;

    for (i = 0; i < p; i++)
        I[i] = i + 1;

    k = (boardSize - 2) / 4;

    for (i = 1; i <= k; i++)
        J.push_back(i);

    for (i = boardSize - k + 2; i <= boardSize; i++)
        J.push_back(i);

    int temp;
    for (i = 1; i <= p; i++)
        for (j = 1; j <= J.size(); j++)
        {
            temp = matrix[i - 1][J[j - 1] - 1];
            matrix[i - 1][J[j - 1] - 1] = matrix[i + p - 1][J[j - 1] - 1];
            matrix[i + p - 1][J[j - 1] - 1] = temp;
        }

    //j=1, i
    //i=k+1, k+1+p
    i = k;
    j = 0;
    temp = matrix[i][j];
    matrix[i][j] = matrix[i + p][j];
    matrix[i + p][j] = temp;

    j = i;
    temp = matrix[i + p][j];
    matrix[i + p][j] = matrix[i][j];
    matrix[i][j] = temp;
}

// create the magic square based on the order provided
void magicSquareType::createMagicSquare()
{
    if (size % 2 == 1) //size is Odd
        OddMagicSquare(board, size);
    else                   //size is even
        if (size % 4 == 0) //doubly even order
        DoublyEvenMagicSquare(board, size);
    else //singly even order
        SinglyEvenMagicSquare(board, size);
}