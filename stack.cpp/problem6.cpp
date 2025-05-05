// next greater element array 
// [4,8,3,1,6,5,3]
// [8,-1,6,6,-1,-1,-1]

// [4,1,3,1,8,5,3]
// /we use while loop bec 8 is the answer of first 4 element so we check condition for all the element
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> problem(vector<int>&v){
    int n=v.size();
    vector<int>res(n,-1);
    stack<int>s;//push index
    s.push(0); 
    for(int i=1;i<n;i++){
        while(!s.empty()&& v[s.top()]<v[i]){
            res[s.top()]=v[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}
//revious greater element then rev perse the element of array and return an array of greter element and then reverse it
// [4 8 3 1 6 5 3]
// [-1 -1 8 3 8 6 5] 
vector<int> problem2(vector<int>v){
    int n=v.size();
    reverse(v.begin(),v.end());
    vector<int>res(n,-1);
    stack<int>s;//push index
    s.push(0); 
    for(int i=1;i<n;i++){
        while(!s.empty()&& v[s.top()]<v[i]){
            res[s.top()]=v[i];
            s.pop();
        }
        s.push(i);
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    vector<int>v={4,8,3,1,6,5,3};
    v=problem2(v);
    for(auto i:v){
        cout<<i<<" ";
    }
}