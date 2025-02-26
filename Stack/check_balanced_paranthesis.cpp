#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalancedParanthesis(string& expression) {
    stack<char> stack;
    for (char ch : expression) {
        switch (ch) {
            case '(':
            case '{':
            case '[':
                stack.push(ch);
                break;

            case ')':
                if (stack.empty() || stack.top() != '(') return false;
                stack.pop();
                break;

            case '}':
                if (stack.empty() || stack.top() != '{') return false;
                stack.pop();
                break;

            case ']':
                if (stack.empty() || stack.top() != '[') return false;
                stack.pop();
                break;
        }
    }
    return stack.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalancedParanthesis(expression))
        cout << "Balanced parenthesis equation" << endl;
    else
        cout << "Not balanced parenthesis equation" << endl;

    return 0;
}
