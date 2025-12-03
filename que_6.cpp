//Q6 ]Simple Transpose and Fast Transpose
#include <iostream>
using namespace std;

// simple transpose: for each column, scan all terms
void simpleTranspose(int a[][3], int b[][3]) {
    b[0][0] = a[0][1]; 
    b[0][1] = a[0][0]; 
    b[0][2] = a[0][2];
    int rows = a[0][0], cols = a[0][1], n = a[0][2];
    int k = 1;
    for (int col = 0; col < cols; ++col) {
        for (int i = 1; i <= n; ++i) {
            if (a[i][1] == col) {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                ++k;
            }
        }
    }
}

// fast transpose: O(n + cols) using counts and start positions
void fastTranspose(int a[][3], int b[][3]) {
    b[0][0] = a[0][1]; b[0][1] = a[0][0]; b[0][2] = a[0][2];
    int cols = a[0][1], n = a[0][2];

    // handle trivial
    if (n == 0) return;

    int *colCount = new int[cols]();
    int *startPos = new int[cols]();

    // count terms in each column (which become rows in transpose)
    for (int i = 1; i <= n; ++i) 
    colCount[a[i][1]]++;

    // starting position for each column in transposed array
    startPos[0] = 1;
    for (int i = 1; i < cols; ++i)
     startPos[i] = startPos[i-1] + colCount[i-1];

    // place terms directly
    for (int i = 1; i <= n; ++i) {
        int col = a[i][1];
        int index = startPos[col]++;
        b[index][0] = a[i][1];
        b[index][1] = a[i][0];
        b[index][2] = a[i][2];
    }

    delete[] colCount;
    delete[] startPos;
}

int main() {
    int a[100][3], b[100][3], f[100][3];
    int r,c,n;
    cout << "Enter rows and columns: ";
    cin >> r >> c;
    cout << "Enter number of non-zero elements: ";
    cin >> n;

    a[0][0] = r; a[0][1] = c; a[0][2] = n;
    cout << "Enter row col value (row and col assumed 0-based):\n";
    for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];

    simpleTranspose(a, b);
    fastTranspose(a, f);

    cout << "\nSimple Transpose:\n";
    for (int i = 0; i <= n; ++i) cout << b[i][0] << " " << b[i][1] << " " << b[i][2] << endl;

    cout << "\nFast Transpose:\n";
    for (int i = 0; i <= n; ++i) cout << f[i][0] << " " << f[i][1] << " " << f[i][2] << endl;

    return 0;
}



