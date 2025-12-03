#include <iostream>
using namespace std;

int stack[100];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

int evalPostfix(char postfix[]) {
    top = -1;
    for (int i = 0; postfix[i]; ++i) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            push(c - '0');
        } else {
            int b = pop();
            int a = pop();
            int result;
            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;
            else if (c == '^') {
                result = 1;
                for (int j = 0; j < b; ++j) result *= a;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char postfix[100];
    
    cout << "Enter postfix expression: ";
    cin >> postfix;
    
    int result = evalPostfix(postfix);
    
    cout << "Postfix: " << postfix << "\n";
    cout << "Result: " << result << "\n";
    
    return 0;
}