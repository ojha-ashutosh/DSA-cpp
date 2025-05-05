// given the head of linklist delete those neighbors who have same value
#include <iostream>
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
void problem(node *&head, node *&tail)
{
    node *h = head;
    while (h != NULL)
    {
        if (h->next != NULL && h->data == h->next->data)
        {
            node *nextptr = h->next;
            h->next = h->next->next;
            if (h->next != NULL)
            {
                h->next->prev = h;
            }
            else
            {
                tail = h;
            }
            delete nextptr;
        }
        h = h->next;
    }
}

int main()
{
    node *new_node = new node(3);
    doublylinklist dll;
    dll.head = new_node;
    dll.tail = new_node;
    dll.insertatlast(10);
    dll.insertatlast(10);
    dll.insertatlast(13);
    dll.insertatlast(23);
    dll.insertatlast(23);
    dll.display();
    problem(dll.head, dll.tail);
    dll.display();
    return 0;
}