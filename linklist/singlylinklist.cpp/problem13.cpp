// given head of linklist rotate the list to the right by k places 
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
node* problem(node* &head,int k){
    node* temp=head;
    node* t=head;
    node* p=head->next;;
    int n=1;
    while(temp->next){
      temp=temp->next;
      n++;
    }
    temp->next=head;
    k=k%n;
    int m=n-k;
    while(m-1!=0){
      t=t->next;
      p=p->next;
      m--;
    }
    t->next=NULL;
    return p;
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
    head=problem(head,2);
    display(head);
    return 0;
}