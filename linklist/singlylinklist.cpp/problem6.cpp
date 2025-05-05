// two link list are equal
// by two pointer approch
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
bool problem(node* &head1,node* &head2){
    if(head1==NULL && head2==NULL) return true;
    node* temp1=head1;
    node* temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data != temp2->data) return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return ((temp1==NULL && temp2 ==NULL));
}


int main(){
    node* head=new node(10);
    insertatlast(head,20);
    insertatlast(head,30);
    insertatlast(head,40);
    insertatlast(head,50);
    insertatlast(head,60);
    display(head);
    node* head2=new node(10);
    insertatlast(head2,20);
    insertatlast(head2,30);
    insertatlast(head2,40);
    insertatlast(head2,50);
    insertatlast(head2,60);
    display(head2);
    bool a=problem(head,head2);
    if(a){
        cout<<"equal";
    }else{
        cout<<"notequal";
    }
    return 0;
}