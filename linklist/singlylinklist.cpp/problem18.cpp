// marge sort in ll
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* findmid(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // Return the middle node
    }

ListNode* marge(ListNode* left, ListNode* right) {
        if(left == nullptr) {
            return right;
        }
        if(right == nullptr) {
            return left;
        }

        ListNode* n = new ListNode(-1); // Dummy node
        ListNode* temp = n;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        // Attach any remaining nodes
        if (left) {
            temp->next = left;
        }
        if (right) {
            temp->next = right;
        }

        ListNode* ans = n->next; // The actual start of the merged list
        delete n; // Free the dummy node
        return ans;
    }

    ListNode* margesortinLL(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid = findmid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Split the list into two halves

        // Apply merge sort on both halves
        left = margesortinLL(left);
        right = margesortinLL(right);

        return marge(left, right); // Merge the sorted halves
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(std::initializer_list<int> values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    Solution solution;

    // Create a linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = createList({4, 2, 1, 3});
    
    std::cout << "Original list: ";
    printList(head);

    // Sort the list
    head = solution.margesortinLL(head);

    std::cout << "Sorted list: ";
    printList(head);

    // Clean up memory (not shown: free the linked list nodes)
    return 0;
}
