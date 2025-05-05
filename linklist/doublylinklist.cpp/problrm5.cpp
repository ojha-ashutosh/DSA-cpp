// given the head of linklist . the value are in incresing order find a pair exist of distint node such that  the sum of the value is x
// return the pair in form of vector[l,r] where i and r are the value stored in 2 node pointer if there are multipel such pair return any of them
// return [-1,-1]
#include <iostream>
#include <vector>
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
vector<int> problem(node *head, node *tail, int target)
{
    vector<int> ans(2, -1); // initialize by maximum value
    node* h=head;
    node* t=tail;
    while (h != t)
    {
        int sum = h->data + t->data;
        if (sum == target)
        {
            ans[0] = h->data;
            ans[1] = t->data;
            return ans;
        }
        else if (sum > target)
        {
            t = t->prev;
        }
        else
        {
            h = h->next;
        }
    }
    return ans;
}


int main()
{
    node *newnode = new node(2);
    doublylinklist dll;
    dll.head = newnode;
    dll.tail = newnode;
    dll.insertatlast(5);
    dll.insertatlast(6);
    dll.insertatlast(8);
    dll.insertatlast(10);
    dll.display();
    vector<int> ans = problem(dll.head, dll.tail, 18);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}