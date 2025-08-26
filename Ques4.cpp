#include <iostream>
using namespace std;
#define n 100   

class Stack {
    char arr[n];
    int top;

public:
    Stack(){
    	top = -1;
	}
	
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == n - 1);
    }
    void push(char c) {
        if (!isFull())
            arr[++top] = c;
        else
            cout << "Stack Overflow!" << endl;
    }
    char pop() {
        if (!isEmpty())
            return arr[top--];
        else {
            cout << "Stack Underflow!" << endl;
        }
    }
    char peek() {
        if (!isEmpty())
            return arr[top];
    }
};


bool IsAlnum(char c) {
    return ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z'));
}

// Precedence function
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char c : infix) {
        if (IsAlnum(c)) {
            postfix += c;   // operand ? output
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // remove '('
        }
        else { // Operator
            while (!s.isEmpty() && prec(s.peek()) >= prec(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    // Pop all remaining operators
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}

