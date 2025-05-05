// given an array of integer heights representing the histogram bar height where the weidth of each bar is 1 return the area largest rectange in the histogram 

// yaha aaisa hai like kise histo fram ki length hai 3 uske keft me 5 ..6 aur 1 and right me 4 5 aur 2 tho max area 5*1=5 brc base is 1...and 
// 1 aur 2 wale include nhi hoge bec 3 se chote hai
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int ans = 0;
    stack<int> s;

    for (int i = 0; i <= n; ++i) {
        while (!s.empty() && (i == n || heights[s.top()] > heights[i])) {
            int h = heights[s.top()];
            s.pop();
            int nse=i;//next smaller
            int pse=s.top();//previos smaller
            int width = s.empty() ? nse : nse -pse - 1;
            ans = max(ans, h * width);
        }
        s.push(i);
    }

    return ans;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3, 0, 2, 1, 5, 6, 2, 3};
    int maxArea = largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << maxArea << endl;
    return 0;
}
