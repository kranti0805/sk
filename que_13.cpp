#include <iostream>
using namespace std;

void shellSort(int src[], int n, int dest[], long long &comps, long long &swaps) {
    for (int i = 0; i < n; ++i) dest[i] = src[i];
    comps = swaps = 0;
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int key = dest[i];
            int j = i;
            while (j >= gap) {
                ++comps;
                if (dest[j-gap] > key) {
                    dest[j] = dest[j-gap];
                    ++swaps;
                    j -= gap;
                } else break;
            }
            dest[j] = key;
        }
    }
}

void radixSort(int src[], int n, int dest[], long long &comps, long long &swaps) {
    for (int i = 0; i < n; ++i) dest[i] = src[i];
    comps = swaps = 0;
    int maxNum = dest[0];
    for (int i = 1; i < n; ++i) if (dest[i] > maxNum) maxNum = dest[i];
    
    for (int exp = 1; maxNum/exp > 0; exp *= 10) {
        int temp[100], count[10] = {0};
        for (int i = 0; i < n; ++i) {
            ++comps;
            int digit = (dest[i]/exp) % 10;
            ++count[digit];
            ++swaps;
        }
        for (int i = 1; i < 10; ++i) count[i] += count[i-1];
        for (int i = n-1; i >= 0; --i) {
            int digit = (dest[i]/exp) % 10;
            temp[--count[digit]] = dest[i];
        }
        for (int i = 0; i < n; ++i) dest[i] = temp[i];
    }
}

int main() {
    int n;
    cout<<"enter array size:";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    int sB[100], rB[100];
    long long cS, sS, cR, sR;
    shellSort(arr, n, sB, cS, sS);
    radixSort(arr, n, rB, cR, sR);
    
    cout << "Shell Sort: ";
    for (int i = 0; i < n; ++i) cout << sB[i] << " ";
    cout << "\nComps: " << cS << " Swaps: " << sS << "\n\n";
    
    cout << "Radix Sort: ";
    for (int i = 0; i < n; ++i) cout << rB[i] << " ";
    cout << "\nComps: " << cR << " Swaps: " << sR << "\n";
    return 0;
}