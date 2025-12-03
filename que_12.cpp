#include <iostream>
using namespace std;

void bubbleSort(int src[], int n, int dest[], long long &comparisons, long long &swaps) {
    for (int i = 0; i < n; ++i) dest[i] = src[i];
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool any = false;
        for (int j = 0; j < n - i - 1; ++j) {
            ++comparisons;
            if (dest[j] > dest[j + 1]) {
                int t = dest[j]; 
                dest[j] = dest[j+1];
                dest[j+1] = t;
                ++swaps;
                any = true;
            }
        }
        if (!any) break;
    }
}

void insertionSort(int src[], int n, int dest[], long long &comparisons, long long &swaps) {
    for (int i = 0; i < n; ++i) dest[i] = src[i];
    comparisons = 0;
    swaps = 0;
    for (int i = 1; i < n; ++i) {
        int key = dest[i];
        int j = i - 1;
        while (j >= 0) {
            ++comparisons;
            if (dest[j] > key) {
                dest[j+1] = dest[j];
                ++swaps;
                --j;
            } else break;
        }
        dest[j+1] = key;
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n, choice;
    
    while (true) {
        cout << "\n===== SORTING COMPARISON =====\n";
        cout << "1. Enter array and sort\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 2) break;
        
        if (choice == 1) {
            cout << "Enter array size: ";
            cin >> n;
            
            if (n <= 0 || n > 100) {
                cout << "Invalid size (1-100)\n";
                continue;
            }
            
            int arr[100];
            cout << "Enter " << n << " elements:\n";
            for (int i = 0; i < n; ++i) cin >> arr[i];
            
            int sortedB[100], sortedI[100];
            long long compB, swapsB, compI, swapsI;
            
            bubbleSort(arr, n, sortedB, compB, swapsB);
            insertionSort(arr, n, sortedI, compI, swapsI);
            
            cout << "\n===== RESULTS =====\n";
            cout << "Original Array: ";
            displayArray(arr, n);
            
            cout << "\nBubble Sort Output: ";
            displayArray(sortedB, n);
            cout << "Comparisons: " << compB << "\nSwaps: " << swapsB << "\n";
            
            cout << "\nInsertion Sort Output: ";
            displayArray(sortedI, n);
            cout << "Comparisons: " << compI << "\nShifts (counted as swaps): " << swapsI << "\n";
            
            cout << "\n===== ANALYSIS =====\n";
            if (compB < compI) cout << "Bubble Sort had FEWER comparisons\n";
            else if (compB > compI) cout << "Insertion Sort had FEWER comparisons\n";
            else cout << "Both had SAME comparisons\n";
            
            if (swapsB < swapsI) cout << "Bubble Sort had FEWER swaps\n";
            else if (swapsB > swapsI) cout << "Insertion Sort had FEWER swaps\n";
            else cout << "Both had SAME swaps\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    cout << "Program ended.\n";
    return 0;
}
