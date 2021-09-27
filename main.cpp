#include <iostream>
#include "boardType.h"
#include "magicSquareType.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "*************************************** Magic Board ************************** \n";
    string title;
    int bSize = 0;
    cout << "Enter  the title of the Magic Square."
         << endl;
    cin >> title;
    cout << "Enter " << bSize << "x" << bSize << " Magic Square."
         << endl
         << endl;
    cout << "Enter  the size of the Magic Square."
         << endl;
    cin >> bSize;
    cout << endl
         << "Enter Magic Square Values (" << bSize << "x"
         << bSize << ")" << endl;

    boardType boardTypeObject(bSize);

    // accept user values from
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            int value;
            cout << "Enter Magic Square Value for (" << i << "x"
                 << j << ")" << endl;
            cin >> value;
            boardTypeObject.setCell(i, j, value);
        }
        cout << endl;
    }
       cout << "column SIZE"<<boardTypeObject.getOrder() <<endl;

    // create the magic board
    magicSquareType magicSquareTypeObject(bSize, title);
}