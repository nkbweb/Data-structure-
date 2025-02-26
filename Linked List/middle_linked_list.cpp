/*
    Problem: Find the Middle of a Linked List
    Approach: Two-pointer technique (Slow and Fast pointer)
    - The slow pointer moves one step at a time.
    - The fast pointer moves two steps at a time.
    - When the fast pointer reaches the end, the slow pointer will be at the middle.
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;

    // Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the middle node of the linked list
ListNode* findMiddle(ListNode* head) {
    if (!head) return nullptr; // Edge case: Empty list

    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast by two steps and slow by one step
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Slow pointer now points to the middle node
}

// Helper function to insert a node at the end
void insertNode(ListNode*& head, int value) {
    if (!head) {
        head = new ListNode(value);
        return;
    }

    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new ListNode(value);
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    ListNode* head = nullptr;

    // Creating the linked list
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Linked List: ";
    printList(head);

    // Finding and printing the middle element
    ListNode* middle = findMiddle(head);
    if (middle)
        cout << "Middle Node: " << middle->val << endl;
    else
        cout << "The list is empty." << endl;

    return 0;
}
