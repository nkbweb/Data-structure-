#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
public:
    CNode* head;
    CircularLinkedList() : head(nullptr) {}

    void insertAtHead(int data) {
        CNode* newNode = new CNode();
        newNode->data = data;

        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        if (head == nullptr) return;

        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.printList();
    return 0;
}
