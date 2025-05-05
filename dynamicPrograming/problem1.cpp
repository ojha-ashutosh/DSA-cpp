// top -down approch ->recursion + memorization(stroing the value of subproblem in table or map)
// buttom-up approch ->tabulation


// fabonacci dp 

#include<iostream>
#include<vector>
using namespace std;

int f_topdoneAproch(int n,vector<int>&fabo){
    if(n==0 || n==1 )return n;
    if(fabo[n] != -1) return fabo[n];
    

    fabo[n]=f_topdoneAproch(n-1,fabo)+f_topdoneAproch(n-2,fabo);
    return fabo[n];
}
int f_bottomupAprooch(int n){
    // tabulation
    vector<int>fabo(n+1,-1);
    fabo[0]=0;
    fabo[1]=1;
    for(int i=2;i<=n;i++){
       fabo[i]=fabo[i-1]+fabo[i-2];
    }
    return fabo[n];
}
int space_optimization(int n){
    if(n==0) return 0;
    int prev1=1;
    int prev2=0;
    for(int i=2;i<=n;i++){
       int curr=prev1+prev2;
       prev2=prev1;
       prev1=curr;
    }
    return prev1;
}
int main(){
    int n;
    cin>>n;
    vector<int>fabo(n+1,-1);
    // 0(n)->time o(n)+o(n) ->space
    cout<<f_topdoneAproch(n,fabo);
    // 0(n)->time o(n) ->space
    cout<<endl<<f_bottomupAprooch(n);
    // 0(n)->time o(1) ->space
    cout<<endl<<space_optimization(n);
}