#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) : data(x), next(NULL), bottom(NULL) {}
};

class Solution {
public:
    // Merge function to merge two sorted linked lists using bottom pointers
    Node* merge(Node* left, Node* right) {
        if (left == NULL) return right;
        if (right == NULL) return left;

        Node dummy(-1);
        Node* temp = &dummy;

        while (left != NULL && right != NULL) {
            if (left->data <= right->data) {
                temp->bottom = left;
                left = left->bottom;
            } else {
                temp->bottom = right;
                right = right->bottom;
            }
            temp = temp->bottom;
        }

        temp->bottom = (left != NULL) ? left : right;

        return dummy.bottom;
    }

    // Flatten function to flatten the linked list
    Node* flatten(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        // Recursively flatten the next part of the list
        head->next = flatten(head->next);

        // Merge the current list with the flattened next list
        head = merge(head, head->next);

        // Ensure the 'next' pointer is null for the flattened list
        head->next = NULL;

        return head;
    }
};

// Utility function to print the flattened linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Main function to test the Solution
int main() {
    // Creating the linked list manually as per example
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;
    Node* flatHead = sol.flatten(head);

    // Print the flattened linked list
    printList(flatHead);

    return 0;
}
