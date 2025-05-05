#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class circularlinkedlist
{    
    public:
    node *head;
    circularlinkedlist()
    {
        head = NULL;
    }
    void insertionathead(int data)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            head->next = newnode;
            return;
        }
        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }
    }
    void display(){
        node* temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
    void printcircular(int m){
        node* temp=head;
        for(int i=1;i<=m;i++){
          cout<<temp->data<<"->";
          temp=temp->next;
        }cout<<endl;
    }
    void insertionatlast(int data){
        node *newnode = new node(data);
        node* temp=head;
        if(head==NULL){
            head=newnode;
            newnode->next=head;
        }
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    void insertionatmiddle(int data,int position){
        node* temp=head;
        node* p=new node(data);
        int i=1;
        while(i<position-1){
           temp=temp->next;
           i++;
        }
        p->next=temp->next;
        temp->next=p;
        
    }
    void deletionatfirst(){
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        node* curr=temp->next;
        temp->next=head->next;
        head=temp->next;
        delete curr;
    }
    void deleteatlast(){
        node* curr=head->next;
        node* prev=head;
        while(curr->next!=head){
            curr=curr->next;
            prev=prev->next;
        }
        prev->next=head;
        delete curr;
    }
    void deleteatmiddle(int position){
        node* curr=head->next;
        node* prev=head;
        int i=1;
        while(i<position-1){
            curr=curr->next;
            prev=prev->next;
            i++;
        }
        prev->next=curr->next;
        delete curr;
    }
};

int main()
{
    circularlinkedlist cll;
    cll.insertionathead(10);
    cll.insertionathead(5);
    cll.insertionathead(1);
    cll.insertionatlast(20);
    cll.insertionatlast(30);
    cll.insertionatmiddle(25,5);
    cll.display();
    cll.deleteatmiddle(5);
    cll.display();
    cll.deletionatfirst();
    cll.display();
    cll.deleteatlast();
    cll.display();
    // cll.printcircular(21);
    return 0;
}