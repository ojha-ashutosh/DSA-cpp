// even odd

#include<iostream>
using namespace std;
bool fn(int n){
    return (n & 1);
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(fn(n)==1){
        cout<<"\n odd";
    }else{
        cout<<"\n even";
    }
}