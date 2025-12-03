//Q7] Write a program to perform addition of two sparse matrices 

#include <iostream>
using namespace std;

int main() {
    int r1, c1, n1;
    int r2, c2, n2;

    // -------- INPUT FIRST SPARSE MATRIX --------
    cout << "Enter rows and columns of Matrix 1: ";
    cin >> r1 >> c1;
    
    cout << "Enter number of non-zero elements in Matrix 1: ";
    cin >> n1;

    int s1[50][3]; // (row, col, value)
    cout << "Enter row col value:\n";
    for (int i = 0; i < n1; i++)
        cin >> s1[i][0] >> s1[i][1] >> s1[i][2];

    // -------- INPUT SECOND SPARSE MATRIX --------
    cout << "Enter rows and columns of Matrix 2: ";
    cin >> r2 >> c2;

    cout << "Enter number of non-zero elements in Matrix 2: ";
    cin >> n2;

    int s2[50][3];
    cout << "Enter row col value:\n";
    for (int i = 0; i < n2; i++)
        cin >> s2[i][0] >> s2[i][1] >> s2[i][2];

    // Check compatibility
    if (r1 != r2 || c1 != c2) {
        cout << "Addition not possible!";
        return 0;
    }

    // -------- ADDITION --------
    int sum[100][3];
    int i = 0, j = 0, k = 0;

    // Merge like merge-sort
    while (i < n1 && j < n2) {
        if (s1[i][0] == s2[j][0] && s1[i][1] == s2[j][1]) {
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2] + s2[j][2];
            i++; j++; k++;
        }
        else if (s1[i][0] < s2[j][0] ||
                (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2];
            i++; k++;
        }
        else {
            sum[k][0] = s2[j][0];
            sum[k][1] = s2[j][1];
            sum[k][2] = s2[j][2];
            j++; k++;
        }
    }

    // Copy remaining elements
    while (i < n1) {
        sum[k][0] = s1[i][0];
        sum[k][1] = s1[i][1];
        sum[k][2] = s1[i][2];
        i++; k++;
    }

    while (j < n2) {
        sum[k][0] = s2[j][0];
        sum[k][1] = s2[j][1];
        sum[k][2] = s2[j][2];
        j++; k++;
    }

    // -------- OUTPUT --------
    cout << "\nResult Sparse Matrix (3-tuple form):\n";
    cout << "Row  Col  Value\n";
    for (int x = 0; x < k; x++)
        if (sum[x][2] != 0)
            cout << sum[x][0] << "    " << sum[x][1] << "    " << sum[x][2] << endl;

    return 0;
}
