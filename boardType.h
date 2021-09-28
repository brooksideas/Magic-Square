#ifndef boardType_h
#define boardType_h
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class boardType:public magicSquareType
{
private:
  static constexpr int BRD_SIZE_MIN = 3;
  static constexpr int BRD_SIZE_MAX = 30;
protected:
  int size;
  vector<vector<int>> board;
public:
  boardType();
  boardType(int);
  ~boardType();
  void setCell(int, int, int);
  const int getCell(int, int);
  const int getOrder();
  const void printGrid();
  bool checkSize(int);
  bool validateBoard(int, int);
};
#endif
