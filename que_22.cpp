void push(Stack &s, char c) {
    if (!isFull(s)) s.arr[++s.top] = c;
}
char pop(Stack &s) {
    if (!isEmpty(s)) return s.arr[s.top--];
    return '#'; // error symbol
}
char peek(Stack &s) {
    if (!isEmpty(s)) return s.arr[s.top];
    return '#';
}

// ---------------- OPERATOR PRECEDENCE ----------------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;  // highest
    return 0;
}

int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^');
}

// ---------------- CONVERT INFIX → POSTFIX ----------------
void infixToPostfix(char infix[], char postfix[]) {
    Stack st; 
    init(st);

    int i = 0, j = 0;

    while (infix[i] != '\0') {

        // skip spaces
        if (infix[i] == ' ') { 
            i++; 
            continue; 
        }

        // ---------- MULTI-DIGIT OPERAND HANDLING ----------
        if ((infix[i] >= '0' && infix[i] <= '9')) {
            while (infix[i] >= '0' && infix[i] <= '9') {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // space separator
            continue;
        }

        // ---------- LEFT PAREN ----------
        if (infix[i] == '(') {
            push(st, '(');
            i++;
        }

        // ---------- RIGHT PAREN ----------
        else if (infix[i] == ')') {
            while (!isEmpty(st) && peek(st) != '(') {
                postfix[j++] = pop(st);
                postfix[j++] = ' ';
            }

            if (isEmpty(st)) {
                cout << "\nError: Mismatched parentheses.\n";
                postfix[0] = '\0';
                return;
            }

            pop(st); // pop '('
            i++;
        }

        // ---------- OPERATOR ----------
        else if (isOperator(infix[i])) {
            while (!isEmpty(st) &&
                   precedence(peek(st)) >= precedence(infix[i])) {
                postfix[j++] = pop(st);
                postfix[j++] = ' ';
            }
            push(st, infix[i]);
            i++;
        }

        // ---------- INVALID CHARACTER ----------
        else {
            cout << "\nError: Invalid character '" << infix[i] << "'\n";
            postfix[0] = '\0';
            return;
        }
    }

    // ---------- POP REMAINING OPERATORS ----------
    while (!isEmpty(st)) {
        if (peek(st) == '(') {
            cout << "\nError: Mismatched parentheses.\n";
            postfix[0] = '\0';
            return;
        }
        postfix[j++] = pop(st);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}


// ---------------- MAIN FUNCTION ----------------
int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter Infix Expression: ";
    cin.getline(infix, MAX);

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0') {
        cout << "\nPostfix Expression: " << postfix << endl;
    }

    return 0;
}
