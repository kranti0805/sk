//addition of polynomial using struct 
#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int power;
};

int main() {
    Term p1[50], p2[50], sum[100], mul[200];
    int n1, n2;

    // -------- INPUT --------
    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n1;
    cout << "Enter coeff and power:\n";
    for (int i = 0; i < n1; i++)
        cin >> p1[i].coeff >> p1[i].power;

    cout << "Enter number of terms in Polynomial 2: ";
    cin >> n2;
    cout << "Enter coeff and power:\n";
    for (int i = 0; i < n2; i++)
        cin >> p2[i].coeff >> p2[i].power;

    // -------- ADDITION (just copy) --------
    int k = 0;

    for (int i = 0; i < n1; i++) sum[k++] = p1[i];
    for (int i = 0; i < n2; i++) sum[k++] = p2[i];

    int sumTerms = k;

    // -------- MERGE LIKE POWERS --------
    for (int i = 0; i < sumTerms; i++) {
        for (int j = i + 1; j < sumTerms; j++) {
            if (sum[i].power == sum[j].power) {
                sum[i].coeff += sum[j].coeff;  // merge
                sum[j].coeff = 0;              // remove duplicate
            }
        }
    }

    // -------- MULTIPLICATION --------
    int m = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            mul[m].coeff = p1[i].coeff * p2[j].coeff;
            mul[m].power = p1[i].power + p2[j].power;
            m++;
        }
    }
    int mulTerms = m;

    // -------- MERGE LIKE TERMS IN MULTIPLICATION --------
    for (int i = 0; i < mulTerms; i++) {
        for (int j = i + 1; j < mulTerms; j++) {
            if (mul[i].power == mul[j].power) {
                mul[i].coeff += mul[j].coeff;
                mul[j].coeff = 0;
            }
        }
    }

    // -------- OUTPUT --------
    cout << "\nPolynomial 1: ";
    for (int i = 0; i < n1; i++)
        cout << p1[i].coeff << "x^" << p1[i].power << "  ";

    cout << "\nPolynomial 2: ";
    for (int i = 0; i < n2; i++)
        cout << p2[i].coeff << "x^" << p2[i].power << "  ";

    cout << "\n\nAddition: ";
    for (int i = 0; i < sumTerms; i++)
        if (sum[i].coeff != 0)
            cout << sum[i].coeff << "x^" << sum[i].power << "  ";

    cout << "\nMultiplication: ";
    for (int i = 0; i < mulTerms; i++)
        if (mul[i].coeff != 0)
            cout << mul[i].coeff << "x^" << mul[i].power << "  ";

    return 0;
}
