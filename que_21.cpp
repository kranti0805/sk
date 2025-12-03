#include <iostream>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

char opStack[100];
int opTop = -1;

void pushOp(char c) { opStack[++opTop] = c; }
char popOp() { return opStack[opTop--]; }
char peekOp() { return opStack[opTop]; }

void infixToPostfix(char infix[], char postfix[]) {
    opTop = -1;
    int outIdx = 0;
    
    for (int i = 0; infix[i]; ++i) {
        char c = infix[i];
        
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[outIdx++] = c;
        }
        else if (c == '(') {
            pushOp(c);
        }
        else if (c == ')') {
            while (opTop != -1 && peekOp() != '(') {
                postfix[outIdx++] = popOp();
            }
            if (opTop != -1) popOp(); // remove '('
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (opTop != -1 && peekOp() != '(' && prec(peekOp()) >= prec(c)) {
                postfix[outIdx++] = popOp();
            }
            pushOp(c);
        }
    }
    
    while (opTop != -1) {
        postfix[outIdx++] = popOp();
    }
    postfix[outIdx] = '\0';
}

void displaySteps(char infix[], char postfix[]) {
    cout << "========== INFIX TO POSTFIX CONVERSION ==========\n\n";
    cout << "Infix Expression:   " << infix << "\n";
    cout << "Postfix Expression: " << postfix << "\n\n";
    
    cout << "Explanation:\n";
    cout << "- Operands are added directly to postfix\n";
    cout << "- Higher precedence operators are processed first\n";
    cout << "- '(' has lowest precedence, '^' has highest\n";
}

int main() {
    char infix[100];
    char postfix[100];
    
    cout << "========== INFIX TO POSTFIX CONVERTER ==========\n\n";
    cout << "Enter infix expression (use +, -, *, /, ^, and parentheses):\n";
    cout << "Example: 2+3*4 or (2+3)*4 or a+b*c\n";
    cout << "Input: ";
    cin >> infix;
    
    infixToPostfix(infix, postfix);
    displaySteps(infix, postfix);
    
    return 0;
}
