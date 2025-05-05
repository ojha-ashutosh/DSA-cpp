#include<iostream>
using namespace std;
class stack{
    int * arr;
    int capacity;
    int top;
    public:
    stack(int c){
        this->capacity=c;
        this->arr=new int[c];
        this->top=-1;
    }
    void push(int data){
        if(top==capacity-1){
            cout<<"overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"underflow"<<endl;
            return;
        }else{
            top--;
        }
    }
    int gettop(){
        if(top==-1){
            cout<<"underflow "<<endl;
            return -100;
        }
        return arr[top];
    }
    void isempty(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
        }else{
            cout<<"stack is not empty"<<endl;
        }
    }
};
int main(){
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(40);
    s.push(10);
    s.push(20);
    s.push(40);
    s.pop();
    int a=s.gettop();
    cout<<a;
}