#include <iostream>
#include <algorithm>
using namespace std;

// Binary Search
int binarySearch(int arr[], int n, int key, int &count) {
    count = 0;
    int start = 0, end = n - 1;
    while (start <= end) {
        count++;
        int mid = (start + end) / 2;
        if (arr[mid] == key) 
        return mid;
        else if (arr[mid] < key) 
        start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

// Fibonacci Search
int fibonacciSearch(int arr[], int n, int key, int &count) {
    count = 0;
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;
    
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    
    int offset = -1;
    while (fib > 1) {
        count++;
        int i = (offset + fib2 < n) ? offset + fib2 : n - 1;
        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else return i;
    }
    
    if (fib1 && (offset + 1 < n) && arr[offset + 1] == key) {
        count++;
        return offset + 1;
    }
    return -1;
}

int main() {
    int n, key, choice;
    cout << "Enter array size: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Binary Search\n";
        cout << "2. Fibonacci Search\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3) break;

        if (choice < 1 || choice > 2) {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "Enter element to search: ";
        cin >> key;

        int pos, count;

        if (choice == 1) {
            cout << "\n--- BINARY SEARCH ---\n";
            pos = binarySearch(arr, n, key, count);
            cout << "Comparisons: " << count << "\n";
            if (pos != -1) cout << "Found at index: " << pos << "\n";
            else cout << "Element not found!\n";
        }
        else if (choice == 2) {
            cout << "\n--- FIBONACCI SEARCH ---\n";
            pos = fibonacciSearch(arr, n, key, count);
            cout << "Comparisons: " << count << "\n";
            if (pos != -1) cout << "Found at index: " << pos << "\n";
            else cout << "Element not found!\n";
        }
    }

    cout << "Program ended.\n";
    return 0;
}