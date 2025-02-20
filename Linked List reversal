#include <iostream>

// Node structure for Linked List
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse the linked list
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next; // Store the next node
        curr->next = prev; // Reverse the current node's pointer
        prev = curr;       // Move prev and curr one step forward
        curr = next;
    }

    return prev; // New head of the reversed list
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    std::cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
