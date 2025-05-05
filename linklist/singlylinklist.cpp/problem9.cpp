// given two sorted linklist merge then in single sorted linklist
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
node* problem(node* &head1,node* head2){
    node* head=new node(-1);
    node* temp=head;
    node* t1=head1;
    node* t2=head2;
    while(t2 != NULL && t1 != NULL){
        if(t1->data>t2->data){
            temp->next=t2;
            t2=t2->next;
        }else{
            temp->next=t1;
            t1=t1->next;
        }
        temp=temp->next;
    }
    if(t1!=NULL){
        temp->next=t1;
    }
    else{
        temp->next=t2;
    }
    return head->next;
}


int main(){
    node* head= new node(1);
    insertatlast(head,2);
    insertatlast(head,5);
    insertatlast(head,7);
    insertatlast(head,9);
    node* head2=new node(3);
    insertatlast(head2,4);
    insertatlast(head2,6);
    insertatlast(head2,8);
    insertatlast(head2,20);
    display(head);
    display(head2);
    node* newhead=problem(head,head2);
    display(newhead);
    return 0;
}
