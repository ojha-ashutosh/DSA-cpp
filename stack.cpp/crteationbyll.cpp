#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};
class stack{
    public:
    node* head;
    int capacity;
    int currsize;
    stack(int c){
        this->capacity=c;
        this->currsize=0;
        this->head=NULL;
    }
    void push(int data){
        if(currsize==capacity){
            cout<<"overflow"<<endl;
            return;
        }
        node* temp=new node(data);
        temp->next=head;
        head=temp;
        this->currsize++;
    };
    void pop(){
        if(head==NULL){
            cout<<"underflow"<<endl;
            return;
        }
        node* t=head;
        head=head->next;
        delete t;
    }
    int size(){
        return this->currsize;
    }
    int gettop(){
        return this->head->data;
    }
};
int main(){
    stack s(5);
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(90);
    s.pop();
    cout<<s.size();
    cout<<endl;
    cout<<s.gettop();
}