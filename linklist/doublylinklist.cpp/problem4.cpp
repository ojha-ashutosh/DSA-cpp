// a critical point in a linklist is  defined as either local maxima or a local minima. given a linklist
// tail ,return an array of length 2 containing{mindistance or maxdistance},where mindistance is the 
// maximum distance bwtwwn 2 critical point and maxdistance is maximum distance between 2 critical point 
// if there is fewer then 2 critical point then return [-1,-1]
// 1->4->3   local maxima
// 12->3->6  local minima
#include<iostream>
#include<vector>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
class doublylinklist
{
public:
    node *head;
    node *tail;
    doublylinklist()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void insertathead(int data)
    {
        node *temp = new node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    void insertatlast(int data)
    {
        node *temp = new node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    void insertatposition(int data, int position)
    {
        if (position == 1)
        {
            insertathead(data);
        }
        int i = 1;
        node *temp = head;
        node *p = new node(data);
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        p->next = temp->next;
        temp->next->prev = p;
        temp->next = p;
        p->prev = temp;
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deleteatfirst()
    {
        node *temp = head;
        if (head == NULL)
        {
            return;
        }
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        delete (temp);
    }
    void deleteatlast()
    {
        node *temp = tail;
        if (tail == NULL)
        {
            return;
        }
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        free(temp);
    }
    void deleteatposition(int position)
    {
        if (position == 1)
        {
            deleteatfirst();
            return;
        }
        node *temp = head;
        int i = 1;
        while (i < position)
        {
            i++;
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete (temp);
    }
};
bool iscriticalpoint(node* curr){
    if(curr->data>curr->prev->data&& curr->data>curr->next->data) {//local maxima
        return true;
    }
    if(curr->data<curr->prev->data&& curr->data<curr->next->data) {//local minima
        return true;
    }
    return false;
}
vector<int> problem(node* &tail)
{
   vector<int> ans(2,100);//initialize by maximum value
   int firstcriticalpoint=-1,lastcriticalpoint=-1;
   node* curr=tail->prev;
   if(curr==NULL){
    ans[0]=ans[1]=-1;
    return ans;
   }
   int currposition=0;
   while(curr->prev!=NULL){
    if(iscriticalpoint(curr)){
       if(firstcriticalpoint==-1){
        firstcriticalpoint=lastcriticalpoint=currposition;
       }else{
        ans[0]=min(ans[0],currposition-lastcriticalpoint);//for minmum distance
        ans[1]=currposition-firstcriticalpoint;//for maximum distance
        lastcriticalpoint=currposition;
       }
       currposition++;
       curr=curr->prev;
    }
   }
   if(ans[0]==100){
    ans[0]=ans[1]=-1;
   }
   return ans;
}

int main()
{   
    node* newnode=new node(1);
    doublylinklist dll;
    dll.head=newnode;
    dll.tail=newnode;
    dll.insertatlast(5);
    dll.insertatlast(2);
    dll.insertatlast(6);
    dll.insertatlast(3);
    dll.display();
    vector<int> ans=problem(dll.tail);
    cout << "Min Distance: " << ans[0] << ", Max Distance: " << ans[1] << endl;
    
    return 0;
}