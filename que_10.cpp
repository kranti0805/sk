#include <iostream>
using namespace std;

// Linear Search (works on both sorted and unsorted)
int linearSearch(int arr[], int n, int key, int &count) {
    count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == key) return i;
    }
    return -1;
}

// Sentinel Search (faster linear on unsorted)
int sentinelSearch(int arr[], int n, int key, int &count) {
    count = 0;
    int last = arr[n-1];
    arr[n-1] = key;
    int i = 0;
    while (arr[i] != key) {
        count++;
        i++;
    }
    arr[n-1] = last;
    if (i < n-1 || last == key) {
        count++;
        return i;
    }
    return -1;
}

int main() {
    int n, key, choice;
    cout << "Enter array size: ";
    cin >> n;

    int arr[100], arrCopy[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arrCopy[i] = arr[i];
    }

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Linear Search (Unsorted)\n";
        cout << "2. Sentinel Search (Unsorted)\n";
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
            cout << "\n--- LINEAR SEARCH ---\n";
            pos = linearSearch(arr, n, key, count);
            cout << "Comparisons: " << count << "\n";
            if (pos != -1) cout << "Found at index: " << pos << "\n";
            else cout << "Element not found!\n";
        }
        else if (choice == 2) {
            cout << "\n--- SENTINEL SEARCH ---\n";
            pos = sentinelSearch(arrCopy, n, key, count);
            cout << "Comparisons: " << count << "\n";
            if (pos != -1) cout << "Found at index: " << pos << "\n";
            else cout << "Element not found!\n";
        }
    }

    cout << "Program ended.\n";
    return 0;
}