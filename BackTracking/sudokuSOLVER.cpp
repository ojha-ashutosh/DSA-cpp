// You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

// Note:
// A Sudoku solution must satisfy all the following conditions-

// 1. Each of the digits 1-9 must occur exactly once in each row.

// 2. Each of the digits 1-9 must occur exactly once in each column.

// 3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub- grids of the grid.
#include <iostream>
#include <vector>
using namespace std;
class sudoku
{
public:
    bool issafe(int row,int col,vector<vector<int>>board,int val){
        for(int i=0;i<board[0].size();i++){
            // for same row
            if(board[row][i]==val){
                return false;
            }
            // for same col
            if(board[i][col]==val){
                return false;
            }
            // for 3*3 matrix
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>> &board)
    {
        int n = board[0].size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == 0)
                {
                    for (int val = 1; val <= 9; val++)
                    {
                        if (issafe(row, col, board, val))
                        {
                            board[row][col] = val;

                            bool aagesolnPOSIBLEhai = solve(board);
                            if (aagesolnPOSIBLEhai)
                            {
                                return true;
                            }
                            else
                            {
                                // back track
                                board[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void sudukosolver(vector<vector<int>> &sudoku)
    {
        solve(sudoku);
    }
};
int main()
{
    vector<vector<int>> v = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sudoku obj;
    obj.sudukosolver(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}