#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool squareValid(vector<vector<char>> &board, int x, int y) {
    vector<int> freq(10, 0);
    for (int i = y - 1; i <= y + 1; i++)
      for (int j = x - 1; j <= x + 1; j++)
        if (isdigit(board[i][j]) && ++freq[board[i][j] - '0'] > 1)
          return false;
    return true;
  }
  bool colValid(vector<vector<char>> &board, int x) {
    vector<int> freq(10, 0);
    for (int i = 0; i < 9; i++)
      if (isdigit(board[x][i]) && ++freq[board[x][i] - '0'] > 1)
        return false;

    return true;
  }
  bool rowValid(vector<vector<char>> &board, int y) {
    vector<int> freq(10, 0);
    for (int i = 0; i < 9; i++)
      if (isdigit(board[i][y]) && ++freq[board[i][y] - '0'] > 1)
        return false;

    return true;
  }
  bool isValidSudoku(vector<vector<char>> &board) {

    int x = 1, y = 1;
    for (int i = 0; i <= 2; i++)
      for (int j = 0; j <= 2; j++)
        if (!squareValid(board, x + (3 * i), y + (3 * j)))
          return false;
    for (int i = 0; i < 9; i++)
      if (!colValid(board, i))
        return false;
    for (int i = 0; i < 9; i++)
      if (!rowValid(board, i))
        return false;

    return true;
  }
};
