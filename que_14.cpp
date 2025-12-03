#include <iostream>
using namespace std;

long long qComps = 0, qSwaps = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        ++qComps;
        if (arr[j] < pivot) {
            ++i;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            ++qSwaps;
        }
    }
    int t = arr[i+1]; arr[i+1] = arr[high]; arr[high] = t;
    ++qSwaps;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout<<"enter array size:";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    qComps = qSwaps = 0;
    quickSort(arr, 0, n-1);
    
    cout << "Quick Sort: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\nComps: " << qComps << " Swaps: " << qSwaps << "\n";
    return 0;
}