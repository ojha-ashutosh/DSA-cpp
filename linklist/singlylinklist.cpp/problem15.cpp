// your are given the head of linklist
// l0->l1->.......->ln-1->ln
// reorder the list
// l0->ln->l1->ln-1->l2->ln-1->.......
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
void insertatlast(node* head,int data){
    node* temp=head;
    node* newnode=new node(data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
      temp->next=newnode;
}
void insertatposition(node* &head,int data,int position){
      node* newnode=new node(data);
      node* temp=head;
      if(position==1){
        insertathead(head,data);
      }
      int i=1;
      while(i<position-1){
        temp=temp->next;
        i++;
      }
      newnode->next=temp->next;
      temp->next=newnode;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}
void deletefromfirst(node* &head){
    node* temp=head;
    head=head->next;
    free(temp);
}
void deleteatlast(node* &head){
    node* temp=head->next;
    node* prev=head;
    while(temp->next!=NULL){
        temp=temp->next;
        prev=prev->next;
    }
    prev->next=NULL;
    free(temp);
    
}
void updatell(node* head,int data,int position){
    node* temp=head;
    int i=0;
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    temp->data=data;
}
void deleteatposition(node* &head,int position){
    node* temp=head->next;
    node* prev=head;
    int i=1;
    while(i<position-1){
        temp=temp->next;
        prev=prev->next;
        i++;
    }
    prev->next=temp->next;
    free(temp);
}
node* problem(node* &head){
    // find middle element
    node* slow=head;
    node* fast =head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    node* curr=slow->next;
    slow->next=NULL;//devide link list into 2 part both have mid node
    node* prev=slow;
    // reverse helf part
    while(curr){
        node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    // merarging two link list
    node* h1=head;
    node* h2=prev;
    while(h1!=h2){
      node* temp=h1->next;
      h1->next=h2;
      h1=h2;
      h2=temp;
    }
    return head;
}


int main(){
    node* head= new node(10);
    insertatlast(head,20);
    insertatlast(head,30);
    insertatlast(head,40);
    insertatlast(head,50);
    insertatlast(head,1000);
    display(head);
    head=problem(head);
    display(head);
    return 0;
}