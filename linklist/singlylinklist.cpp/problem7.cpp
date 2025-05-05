// given the heads of two linklist ....return the node at which the two linklist intersect ....if they dont intersect return null;
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
int getlength(node* head){
    node* temp=head;
    int height =0;
    while(temp!=NULL){
        temp=temp->next;
        height++;
    }
    return height;
}
node* movepointer(node* head,int k){
    node* t=head;
    while(k--){
        t=t->next;
    }
    return t;
}
node* problem(node* &head1,node* head2){
    int l1=getlength(head1);
    int l2=getlength(head2); 
    // move pointer of larger linklist
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        int k=l1-l2;
        ptr1=movepointer(head1,k);
        ptr2=head2;
    }else{
        int k=l2-l1;
        ptr1=head1;
        ptr2=movepointer(head2,k);
    }

    while(ptr1!=NULL || ptr2 !=NULL ){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
}


int main(){
    node* head= new node(1);
    insertathead(head,1);
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,14);
    insertathead(head,4);
    insertathead(head,4);
    node* head2=new node(12);
    insertathead(head2,5);
    insertathead(head2,6);
    insertathead(head2,6);
    // making intersection
    head2->next->next->next->next=head->next->next->next;
    display(head);
    display(head2);
    node* ans=problem(head,head2);
    if(ans){
        cout<<ans->data;
    }else{
        cout<<-1;
    }
    return 0;
}
