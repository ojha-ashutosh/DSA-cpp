// rotate 90 degree 2d matrix
// step1->transpose
// step2->rotate each row of transpose matrix
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void transpose(vector<vector<int>>& m){
        int n=m.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(m[i][j],m[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(auto& i:matrix){
            reverse(i.begin(),i.end());
        }
    }
};
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution sol;
    sol.rotate(matrix);

    // Print the rotated matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
