// shop in candy store
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
vector<int> shop_candy(vector<int>candy,int k)
{
    vector<int>ans;
    int n=candy.size();
    int m=n;
    sort(candy.begin(),candy.end());
    int min_cost=0;
    for(int i=0;i<n;i++){
       min_cost+=candy[i];
       for(int j=0;j<k;j++){
          n--;
       }
    }
    ans.push_back(min_cost);
    n=m;
    m=0;
    int max_cost=0;
    for(int i=n-1;i>=m;i--){
        max_cost+=candy[i];
        for(int j=0;j<k;j++){
           m++;
        }
    }
    ans.push_back(max_cost);
    return ans;
}
int main(){
    vector<int>candy={3,2,1,4};
    int k=2;
    vector<int>ans=shop_candy(candy,k);
    for(auto i:ans){
        cout<<i<<" ";
    }
}