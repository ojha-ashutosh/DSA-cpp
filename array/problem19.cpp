#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> GENERATErow(int n){
        vector<int>temp;
        temp.push_back(1);
        int ans=1;
        for(int i=1;i<n;i++){
            ans*=(n-i);
            ans/=i;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
           vector<int>temp;
           temp=GENERATErow(i);
           ans.push_back(temp);
        }
        return ans;
    }
};
int main() {
    Solution sol; // Create an instance of the Solution class.
    int n; 
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> n; // Input for the number of rows.
    
    // Generate Pascal's Triangle.
    vector<vector<int>> result = sol.generate(n);

    // Print the result.
    cout << "Pascal's Triangle with " << n << " rows:\n";
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
