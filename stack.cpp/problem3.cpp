// remove element from given index
#include<iostream>
#include<stack>
using namespace std;
void problem(stack<int>&s,int position){
    stack<int>m;
    int i=1;
    while(i!=position){
        int c=s.top();
        s.pop();
        m.push(c);
        i++;
    }
    s.pop();
    while(not m.empty()){
        int a=m.top();
        m.pop();
        s.push(a);
    }
}
void problem2(stack<int>&s,int p){
    if(p==1){
      s.pop();
      return;
    }
    int c=s.top();
    s.pop();
    problem2(s,p-1);
    s.push(c);
}
void insertatbottom(stack<int>&s,int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    int curr=s.top();
    s.pop();
    insertatbottom(s,data);
    s.push(curr);
}


int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // problem(s,3);
    problem2(s,3);
    // insertatbottom(s,9);
    while(not s.empty()){
        int c=s.top();
        s.pop();
        cout<<c<<" ";
    }cout<<endl;
}