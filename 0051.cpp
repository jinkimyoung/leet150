

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> board(n, string(n, '.'));

        if (n <= 0) return ret;
        backtrace(board, ret, 0);
        return ret;
    }

    void backtrace(vector<string> &board, vector<vector<string>> &ret, int row)
    {
        if (row == board.size())
        {
            ret.push_back(board);
            return ;
        }

        // iterate every possible position
        for (int col = 0; col < board.size(); col++)
            if (isValid(board, row, col))
            {
                board[row][col] = 'Q';          // make decision
                backtrace(board, ret, row+1);   // next iteration
                board[row][col] = '.';          // back-tracking       
            }
    }
    bool isValid(vector<string> &board, int row, int col)
    {
        // check col
        for (int i = row; i >= 0; i--)
            if (board[i][col] == 'Q')   return false;

        // left diagonal - 대각선
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        // left diagonal - 대각선
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }
};