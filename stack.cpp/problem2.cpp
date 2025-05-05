// /insert at position 
#include<iostream>
#include<stack>
using namespace std;
void problem(stack<int>&s,int data,int p){
    stack<int>m;
    int i=1;
    while(i!=p){
        int c=s.top();
        s.pop();
        m.push(c);
        i++;
    }
    s.push(data);
    while(not m.empty()){
       int a=m.top();
       m.pop();
       s.push(a); 
    }
}
void problem2(stack<int>&s,int p,int data){
    if(p==1){
        s.push(data);
        return;
    }
    int curr=s.top();
    s.pop();
    problem2(s,p-1,data);
    s.push(curr);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // problem(s,5,4);
    problem2(s,3,5);
    while(not s.empty()){
        int a=s.top();
        cout<<a<<" ";
        s.pop();
    }

} 