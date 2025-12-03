#include <iostream>
using namespace std;

long long factStack(int n) {
    if (n < 0) return -1;
    long long result = 1;
    for (int i = n; i >= 1; --i) result *= i;
    return result;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    
    long long result = factStack(n);
    
    if (result == -1) {
        cout << "Invalid input\n";
    } else {
        cout << "Factorial of " << n << " is: " << result << "\n";
    }
    
    return 0;
}