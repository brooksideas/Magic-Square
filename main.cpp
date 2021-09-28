#include <iostream>
#include <string>
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
     getline(cin, title);
     // cin >> title;
     cout << "Enter " << bSize << "x" << bSize << " Magic Square."
          << endl
          << endl;
     cout << "Enter  the size of the Magic Square."
          << endl;
     cin >> bSize;
     cout << endl
          << "Display Magic Square for Values (" << bSize << "x"
          << bSize << ")" << endl;

     // create the initial board
     boardType boardTypeObject(bSize);

     // create the magic board
     magicSquareType magicSquareTypeObject(bSize, title);
}