#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertathead(node* &head,int data){
    node* newnode=new node(data);
    newnode->next=head;
    head=newnode;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}
node* solve(node* &head,int k){
    node* curr=head;
    node* prev=NULL;
    int i=0;
    while(curr!=NULL && i<k){
        node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        i++;
    }
    if(curr!=NULL){
    node* newhead=solve(curr,k);
    head->next=newhead;
   }
    return prev;
    
}
int main(){
    node* head= new node(1);
    insertathead(head,1);
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,4);
    insertathead(head,4);
    insertathead(head,5);
    insertathead(head,6);
    insertathead(head,6);
    display(head);
    head=solve(head,2);
    display(head);
    return 0;
}