#include<iostream>
#include<limits.h>
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
void count(node* &head){
    int c=0;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    node* temp=head;
    while(temp!=NULL){
        c++;
        if(temp->data<mini){
            mini=temp->data;
        }
        if(temp->data>maxi){
            maxi=temp->data;
        }
        temp=temp->next;
    }
    cout<<c;
    cout<<" "<<mini<<"  "<<maxi;
}
int main(){
    node* head= new node(5);
    insertathead(head,4);
    insertathead(head,1);
    display(head);
    insertatlast(head,100);
    insertatlast(head,23);
    display(head);
    insertatposition(head,32,3);
    insertatposition(head,300,4);
    insertatposition(head,3,1);
    display(head);
    updatell(head,6,2);
    display(head);
    deletefromfirst(head);
    display(head);
    deleteatlast(head);
    display(head);
    deleteatposition(head,4);
    display(head);
    count(head);
    return 0;
}
