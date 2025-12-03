//Q5] Write a program to Implement basic array operations such as insert, delete, and merge, 
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int A[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    // ===== PRINT WITH ADDRESSES =====
    cout << "\nArray with Memory Addresses:\n";
    for (int i = 0; i < n; i++)
        cout << "A[" << i << "] = " << A[i] << " at " << &A[i] << endl;

    // ===== INSERT =====
    int pos, val;
    cout << "\nInsert at position: ";
    cin >> pos;
    cout << "Value: ";
    cin >> val;

    for (int i = n; i > pos; i--){
        A[i] = A[i - 1];
    }
    A[pos] = val;
    n++;//one element inserted so size will increase by 1
    cout << "After insert: ";
    for (int i = 0; i < n; i++){
     cout << A[i] << " ";
    }
    // ===== DELETE =====
    int delPos;
    cout << "\n\nDelete at position: ";
    cin >> delPos;

    for (int i = delPos; i < n - 1; i++)
        A[i] = A[i + 1];
    n--;

    cout << "After delete: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";

    // ===== MERGE =====
    int m;
    cout << "\n\nEnter size of second array: ";
    cin >> m;

    int B[50];
    cout << "Enter " << m << " elements:\n";
    for (int i = 0; i < m; i++){
        cin >> B[i];
    }
    for (int i = 0; i < m; i++){
        A[n + i] = B[i];
     }
    n = n + m;

    cout << "After merge: ";
    for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
    }
    return 0;
}