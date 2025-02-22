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

    void insertAtTail(int data) {
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
    }

    void deleteNode(int key) {
        if (head == nullptr) return;

        CNode* temp = head;
        CNode* prev = nullptr;

        while (temp->data != key) {
            if (temp->next == head) return;
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == head && prev == nullptr) {
            head = nullptr;
            delete temp;
            return;
        }

        if (temp == head) {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = head->next;
            prev->next = head;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
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
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.deleteNode(20);
    list.printList();
    return 0;
}
