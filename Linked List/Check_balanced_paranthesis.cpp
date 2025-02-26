#include <iostream>
#include <string>

using namespace std;

// Node structure for linked list-based stack
struct Node {
    char data;
    Node* next;
    
    Node(char value) {
        data = value;
        next = nullptr;
    }
};

// Stack implementation using linked list
class Stack {
private:
    Node* topNode;  // Pointer to the top node

public:
    Stack() {
        topNode = nullptr;  // Initialize stack as empty
    }

    // Push operation
    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) return;  // Prevent popping from an empty stack
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Top operation
    char top() {
        if (!isEmpty()) return topNode->data;
        return '\0'; // Return null character if stack is empty
    }

    // Check if stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) pop();
    }
};

// Function to check if parentheses are balanced using linked list stack
bool isBalancedParenthesis(string& expression) {
    Stack stack;

    for (char ch : expression) {
        switch (ch) {
            case '(':
            case '{':
            case '[':
                stack.push(ch);
                break;

            case ')':
                if (stack.isEmpty() || stack.top() != '(') return false;
                stack.pop();
                break;

            case '}':
                if (stack.isEmpty() || stack.top() != '{') return false;
                stack.pop();
                break;

            case ']':
                if (stack.isEmpty() || stack.top() != '[') return false;
                stack.pop();
                break;
        }
    }

    return stack.isEmpty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalancedParenthesis(expression))
        cout << "Balanced parenthesis equation" << endl;
    else
        cout << "Not balanced parenthesis equation" << endl;

    return 0;
}
