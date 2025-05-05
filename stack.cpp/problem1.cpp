// copy stack
// by iteration as well as recursion
#include<iostream>
#include<stack>
using namespace std;
stack<int> problem(stack<int>s){
    stack<int>temp;
    while(not s.empty()){
        int a=s.top();
        s.pop();
        temp.push(a);
    }
    stack<int>res;
    while(not temp.empty()){
        int a=temp.top();
        temp.pop();
        res.push(a);
    }
    return res;
}
void problem2(stack<int> &s,stack<int> & res){

    if(s.empty()){
        return;
    }
    int curr=s.top();
    s.pop();
    problem2(s,res);
    res.push(curr);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    stack<int>copy;
    // copy=problem(s);
    problem2(s,copy);
    while(not copy.empty()){
        int a=copy.top();
        cout<<a<<" ";
        copy.pop();
    }

}