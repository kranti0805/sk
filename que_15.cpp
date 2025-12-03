#include<iostream>
using namespace std;

struct Node { int coeff, power; Node *next; };

Node* createNode(int c, int p) {
    Node *n = new Node();
    n->coeff = c; n->power = p; n->next = NULL;
    return n;
}

Node* insertSorted(Node *head, int coeff, int power) {
    Node *newNode = createNode(coeff, power);
    if (!head) return newNode;
    
    if (head->power < power) {
        newNode->next = head;
        return newNode;
    }
    
    Node *temp = head;
    while (temp->next && temp->next->power > power) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* addPoly(Node *p1, Node *p2) {
    Node *result = NULL, *tail = NULL;
    while (p1 && p2) {
        Node *newNode;
        if (p1->power == p2->power) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) newNode = createNode(sum, p1->power);
            else { p1 = p1->next; p2 = p2->next; continue; }
            p1 = p1->next; p2 = p2->next;
        } else if (p1->power > p2->power) {
            newNode = createNode(p1->coeff, p1->power);
            p1 = p1->next;
        } else {
            newNode = createNode(p2->coeff, p2->power);
            p2 = p2->next;
        }
        if (!result) result = newNode;
        else tail->next = newNode;
        tail = newNode;
    }
    while (p1) {
        Node *newNode = createNode(p1->coeff, p1->power);
        if (!result) result = newNode;
        else tail->next = newNode;
        tail = newNode;
        p1 = p1->next;
    }
    while (p2) {
        Node *newNode = createNode(p2->coeff, p2->power);
        if (!result) result = newNode;
        else tail->next = newNode;
        tail = newNode;
        p2 = p2->next;
    }
    return result;
}

void display(Node *p) {
    if (!p) { cout << "0\n"; return; }
    bool first = true;
    while (p) {
        if (p->coeff != 0) {
            if (!first && p->coeff > 0) cout << " + ";
            else if (!first && p->coeff < 0) cout << " ";
            cout << p->coeff << "x^" << p->power;
            first = false;
        }
        p = p->next;
    }
    cout << "\n";
}

Node* inputPolynomial() {
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;
    
    Node *head = NULL;
    cout << "Enter coefficient and power (in descending order of power):\n";
    for (int i = 0; i < terms; ++i) {
        int coeff, power;
        cout << "Term " << i+1 << " - Coefficient: ";
        cin >> coeff;
        cout << "Term " << i+1 << " - Power: ";
        cin >> power;
        head = insertSorted(head, coeff, power);
    }
    return head;
}

int main() {
    cout << "POLYNOMIAL ADDITION \n\n";
    
    cout << "\nInput Polynomial 1 (P1)\n";
    Node *p1 = inputPolynomial();
    
    cout << "\nInput Polynomial 2 (P2)\n";
    Node *p2 = inputPolynomial();
    
    cout << "\n RESULTS \n";
    cout << "P1: ";
    display(p1);
    
    cout << "P2: ";
    display(p2);
    
    Node *result = addPoly(p1, p2);
    cout << "P1 + P2: ";
    display(result);
    
    return 0;
}
