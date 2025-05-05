#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Queue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int size;

    // constructor
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void enqueue(int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void dequeue()
    {
        if (head == NULL)
        {
            cout << "queue is empty\n";
        }
        else
        {
            Node *oldhead = head;
            head = head->next;
            if (head == NULL)
                tail = NULL;
            oldhead->next = NULL;
            delete (oldhead);
        }
    }
    void getfront()
    {
        if (head == NULL)
        {
            cout << "queue is empty\n";
        }
        cout << head->data << endl;
    }
    void getsize()
    {
        cout << this->size << endl;
    }
    void isempty()
    {
        if (head == NULL)
        {
            cout << "empty" << endl;
        }
    }
    void print()
    {
        while (head != NULL)
        {
            cout << this->head->data << "\n";
            dequeue();
        }
    }
};
int main()
{
    Queue q;
    q.enqueue(40);
    q.enqueue(100);
    // q.getfront();
    q.enqueue(140);
    q.enqueue(1020);
    q.dequeue();
    q.print();
}