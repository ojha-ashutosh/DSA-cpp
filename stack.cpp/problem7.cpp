// given a series of N daily quotes for a stock we need to calculate the span of the stack's price for all N days.
// the spam of the stock price in one day is the maximum no of consecutive days in which (starting from that day and going backword ) 
// for which stack price is equal to or leass than to the price of that day

// 60 80 400 30 5
// 1  2  3  1  1

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> previousgreterelement(vector<int>&v){
    reverse(v.begin(),v.end());
    int n=v.size();
    vector<int>res(n,-1);
    stack<int>s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && v[s.top()]<v[i]){
            res[s.top()]=n-i-1;//index of next greter element
            // n-i-1 formula come from like 5 is at 4 index and after reverse it will be on 0...n-i-1=5-4-1=0
            s.pop();
        }
        s.push(i);
    }
    reverse(res.begin(),res.end());
    reverse(v.begin(),v.end());
    return res;
}
int main(){
    vector<int>v={60, 80, 400, 30, 5};
    vector<int>r=previousgreterelement(v);
    for(int i=0;i<v.size();i++){
        cout<<(i-r[i])<<" ";
    }
}