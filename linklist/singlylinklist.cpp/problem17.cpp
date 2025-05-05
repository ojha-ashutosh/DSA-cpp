// clone a linklist with random pointer
#include <iostream>
#include <unordered_map>
using namespace std;

// Node definition
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution {
public:
    void create(Node*& head, Node*& tail, int data) {
        Node* newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while (temp != NULL) {
            create(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        unordered_map<Node*, Node*> map;
        Node* t1 = clonehead;
        Node* t2 = head;
        while (t2 != NULL) {
            map[t2] = t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        Node* t3= clonehead;
        Node* t4 = head;
        while (t3 != NULL) {
            t3->random = map[t4->random];
            t3 = t3->next;
            t4 = t4->next;
        }

        return clonehead;
    }
};
int main() {
    // Creating a list with 3 nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Linking the nodes
    head->next = second;
    second->next = third;

    // Setting random pointers
    head->random = third;     // 1's random points to 3
    second->random = head;    // 2's random points to 1
    third->random = second;   // 3's random points to 2

    // Create the solution object
    Solution sol;
    Node* clonedList = sol.copyRandomList(head);

    // Output to check if the cloning is correct
    Node* temp = clonedList;
    while (temp != nullptr) {
        cout << "Value: " << temp->val;
        if (temp->random) {
            cout << ", Random points to: " << temp->random->val << endl;
        } else {
            cout << ", Random points to: nullptr" << endl;
        }
        temp = temp->next;
    }

    return 0;
}
