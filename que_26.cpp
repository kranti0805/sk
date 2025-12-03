#include <iostream>
using namespace std;

long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n-1);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    
    if (n < 0) {
        cout << "Invalid input\n";
        return 0;
    }
    
    long long result = fact(n);
    cout << "Factorial of " << n << " is: " << result << "\n";
    
    return 0;
}