#ifndef boardType_h
#define boardType_h
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class boardType
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
  int getCell(int, int);
  int getOrder() const;
  void printGrid() const;
  bool checkSize(int);
  int validateBoard(int, int);
  vector<vector<int>> getBoard();
};
#endif
