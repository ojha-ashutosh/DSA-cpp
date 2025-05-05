#include <iostream>
#include <vector>
using namespace std;
class RATinMAZE
{
private:
    bool issafe(int i, int j, int m, int n, vector<vector<int>> visted, vector<vector<int>> maze)
    {
        if ((i >= 0 && i < n) && (j >= 0 && j < m) && maze[i][j] == 1 && visted[i][j] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
void soln(vector<vector<int>> maze, string output, vector<string> &ans, int i, int j, vector<vector<int>> visited, int n, int m)
{
    if (i == n-1 && j == m-1)
    {
        ans.push_back(output);
        return;
    }

    visited[i][j] = 1;

    // Down
    int newi = i + 1; 
    int newj = j;
    if (issafe(newi, newj, m, n, visited, maze))
    {
        output.push_back('D');
        soln(maze, output, ans, newi, newj, visited, n, m);
        output.pop_back(); // Backtrack
    }

    // Left
    newi = i; 
    newj = j - 1;
    if (issafe(newi, newj, m, n, visited, maze))
    {
        output.push_back('L');
        soln(maze, output, ans, newi, newj, visited, n, m);
        output.pop_back(); // Backtrack
    }

    // Right
    newi = i; 
    newj = j + 1;
    if (issafe(newi, newj, m, n, visited, maze))
    {
        output.push_back('R');
        soln(maze, output, ans, newi, newj, visited, n, m);
        output.pop_back(); // Backtrack
    }

    // Up
    newi = i - 1;
    newj = j;
    if (issafe(newi, newj, m, n, visited, maze))
    {
        output.push_back('U');
        soln(maze, output, ans, newi, newj, visited, n, m);
        output.pop_back(); // Backtrack
    }

    visited[i][j] = 0; // Reset visited for backtracking
}


public:
    vector<string> rIn(vector<vector<int>> maze)
    {
        vector<string> ans;
        if (maze[0][0] == 0)
        {
            return ans;
        }
        int m = maze.size();      // Number of rows
        int n = maze[0].size();   // Number of columns
        vector<vector<int>> visited(m, vector<int>(n, 0)); 
        string output;
        soln(maze, output, ans, 0, 0, visited, n, m);
        return ans;
    }
};
int main() {
    RATinMAZE rat;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = rat.rIn(maze);
    for (string path : result) {
        cout << path << " ";
    }
    return 0;
}
