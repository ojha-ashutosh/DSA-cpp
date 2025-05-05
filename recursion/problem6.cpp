// power set
#include<iostream>
#include<vector>
using namespace std;
void solve(int index,vector<int>set,vector<int>output,vector<vector<int>>&result){
    if(index>set.size()-1){
        result.push_back(output);
        return;
    }

    // exclude
    solve(index+1,set,output,result);

    // include
    output.push_back(set[index]);
    solve(index+1,set,output,result);
}
vector<vector<int>> powerset(vector<int>set){
    vector<int>output;
    vector<vector<int>>result;
    solve(0,set,output,result);
    return result;
}
int main() {
    vector<int> set = {1, 2, 3};
    vector<vector<int>> result = powerset(set);

    // Printing the power set
    cout << "Power set: \n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
    return 0;
}
