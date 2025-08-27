#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int val) {
        if (!isFull())
            arr[++top] = val;
        else
            cout << "Stack Overflow!" << endl;
    }

    int pop() {
        if (!isEmpty())
            return arr[top--];
        else {
            cout << "Stack Underflow!" << endl;
            return 0;
        }
    }

    int peek() {
        if (!isEmpty())
            return arr[top];
        return 0;
    }
};

// Custom isDigit function
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to evaluate postfix expression
int evaluatePostfix(char expr[]) {
    Stack st;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (isDigit(c)) {
            // Convert char to int and push
            st.push(c - '0');   // asci val of '0' is 48
        } else {
            // Operator: pop two operands
            int val2 = st.pop();
            int val1 = st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++)
                        res *= val1;
                    st.push(res);
                    break;
                }
                default: cout << "Invalid operator: " << c << endl;
            }
        }
    }

    return st.pop();
}

int main() {
    char postfix[MAX];
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}


