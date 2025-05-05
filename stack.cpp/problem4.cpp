// reverse stack
#include<iostream>
#include<stack>
using namespace std;
void problem(stack<int>&s){
   stack<int>t1;
   stack<int>t2;
   while(not s.empty()){
    int curr=s.top();
    s.pop();
    t1.push(curr);
   }
   while(not t1.empty()){
    int curr=t1.top();
    t1.pop();
    t2.push(curr);
   }
    while(not t2.empty()){
    int curr=t2.top();
    t2.pop();
    s.push(curr);
   } 

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
// recursive approch
void problem2(stack<int>&s){
    if(s.empty()){
        return;
    }
    int c=s.top();
    s.pop();
    problem2(s);
    insertatbottom(s,c);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // problem(s);
    problem2(s);
    while(not s.empty()){
        int c=s.top();
        s.pop();
        cout<<c<<" ";
    }cout<<endl;

}
