// GIVEN THE HEAD OF LINKLIST REMOVE KTH NODE FROM LAST
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
void problem(node* &head){
    if (head == nullptr || head->next == nullptr) // Check if list is empty or has only one node
    return;
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            node* p=temp->next;
            temp->next=p->next;
            delete(p);
        }
        else{
            temp=temp->next;
        }
    }
    //head need to be removed
    while(head!=NULL && head->next!=NULL && head->data==head->next->data){
            node* p=head;
            head=head->next;
            delete(p);
    }
}
int getlenghth(node* head){
    node* temp=head;
    int i=0;
    while(temp!=NULL){
       temp=temp->next;
       i++;
    }
    return i;
}
node* move(node* head,int s){
    node* t=head;
    int i=1;
    while(i!=s){
        t=t->next;
        i++;
    }
    return t;
}
void problem(node* &head,int k){
    int length=getlenghth(head);  
    if(length==k){
        // delete head
        node* temp=head;
        head=head->next;
        delete temp;
        return;
    } 
    int steps=length-k;
    node* curr=move(head,steps);
    node* temp=curr->next;
    curr->next=temp->next;
    delete temp;
}
// by two pointer aproch .....treversing linllist only one time
void problem2(node* &head,int k){
    node* ptr1=head;
    node* ptr2=head;

    // move ptr2 by k steps
    while(k--){
        ptr2=ptr2->next;
    }
    // if k==lenth of linklist ptr2==NULL....so we have to delete head node
    if(ptr2==NULL){
        node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    //when ptr2 is on null ptr1 will be on the node to be deleted so we will stop ptr2 on last node so ptr1 will be on k-1 node from last
    while(ptr2->next!=NULL){
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }
    node* temp=ptr1->next;
    ptr1->next=temp->next;
    delete temp;
}

int main(){
    node* head= new node(10);
    insertathead(head,20);
    insertathead(head,30);
    insertathead(head,40);
    insertathead(head,50);
    display(head);
    problem(head,5);
    display(head);
    problem2(head,3);
    display(head);
    return 0;
}