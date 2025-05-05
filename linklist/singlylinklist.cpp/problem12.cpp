// given linklist is palindrome or not
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
bool problem(node* &head){
    node* slow=head;
    node* fast=head;
    // find middle element
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    // break link list
    node* curr=slow->next;
    node* prev =slow;
    slow->next=NULL;
    // reverse 2nd helf of linklist
    while(curr){
        node* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr = nextnode;
    }
    // check node are equal or not
    node* head1=head;
    node* head2=prev;
    while(head2){
    if (head1->data != head2->data){
        return false;
    }
    head1=head1->next;
    head2=head2->next;
    }
    return true;
}

int main(){
    node* head= new node(1);
    insertatlast(head,2);
    insertatlast(head,3);
    insertatlast(head,3);
    insertatlast(head,2);
    insertatlast(head,1);
    display(head);
    bool a=problem(head);
    if(a){
        cout<<"yeas";
    }else{
        cout<<"no";
    }
    return 0;
}