//Q8] Write a program to Implement polynomial addition and multiplication operations using array representation. 
#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    int p1[50][2], p2[50][2];
    int sum[100][2], mul[200][2];

    // ------------ INPUT POLYNOMIAL 1 ------------
    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n1;
    cout << "Enter coeff and power:\n";
    for (int i = 0; i < n1; i++)
        cin >> p1[i][0] >> p1[i][1];

    // ------------ INPUT POLYNOMIAL 2 ------------
    cout << "Enter number of terms in Polynomial 2: ";
    cin >> n2;
    cout << "Enter coeff and power:\n";
    for (int i = 0; i < n2; i++)
        cin >> p2[i][0] >> p2[i][1];

    // ------------ ADDITION (combine same powers) ------------
    int k = 0;

    // copy p1 into sum
    for (int i = 0; i < n1; i++) {
        sum[k][0] = p1[i][0];
        sum[k][1] = p1[i][1];
        k++;
    }

    // copy p2 into sum
    for (int i = 0; i < n2; i++) {
        sum[k][0] = p2[i][0];
        sum[k][1] = p2[i][1];
        k++;
    }

    int sumTerms = k;

    // ----- MERGE SAME POWERS (VERY SIMPLE DOUBLE LOOP) -----
    for (int i = 0; i < sumTerms; i++) {
        for (int j = i + 1; j < sumTerms; j++) {
            if (sum[i][1] == sum[j][1]) {       // same power
                sum[i][0] = sum[i][0] + sum[j][0];        // add coefficients

                // shift remaining items left
                for (int t = j; t < sumTerms - 1; t++) {
                    sum[t][0] = sum[t+1][0];
                    sum[t][1] = sum[t+1][1];
                }
                sumTerms--;    // reduce size
                j--;           // re-check same j index
            }
        }
    }

    // ------------ MULTIPLICATION (NO MERGE YET) ------------
    int m = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            mul[m][0] = p1[i][0] * p2[j][0];     // multiply coefficients
            mul[m][1] = p1[i][1] + p2[j][1];     // add powers
            m++;
        }
    }
    int mulTerms = m;

    // ------------ MERGE FOR MULTIPLICATION ------------
    for (int i = 0; i < mulTerms; i++) {
        for (int j = i + 1; j < mulTerms; j++) {
            if (mul[i][1] == mul[j][1]) {
                mul[i][0] += mul[j][0];

                // shift left
                for (int t = j; t < mulTerms - 1; t++) {
                    mul[t][0] = mul[t+1][0];
                    mul[t][1] = mul[t+1][1];
                }

                mulTerms--;
                j--;
            }
        }
    }

    // ------------ OUTPUT ------------
    cout << "\nPolynomial 1: ";
    for (int i = 0; i < n1; i++)
        cout << p1[i][0] << "x^" << p1[i][1] << "  ";

    cout << "\nPolynomial 2: ";
    for (int i = 0; i < n2; i++)
        cout << p2[i][0] << "x^" << p2[i][1] << "  ";

    cout << "\n\nAddition (Combined): ";
    for (int i = 0; i < sumTerms; i++)
        cout << sum[i][0] << "x^" << sum[i][1] << "  ";

    cout << "\nMultiplication (Combined): ";
    for (int i = 0; i < mulTerms; i++)
        cout << mul[i][0] << "x^" << mul[i][1] << "  ";

    return 0;
}




