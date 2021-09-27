#ifndef magicSquareType_h
#define magicSquareType_h
#include<string>
#include<iostream> 
using namespace std;
class magicSquareType
{ 
  private:
  string title;
  public:
  magicSquareType();
  magicSquareType(int);
  ~magicSquareType();

magicSquareType(int, string);
void createMagicSquare();
void printMagicSquare() const;
void readMagicSquare();
bool validateMagicSquare() const;
void clearMagicSquare();
int magicNumber() const; 
string getTitle() const; 
void setTitle(string);
};
#endif
