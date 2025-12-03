//karatsuba 

#include <iostream>
using namespace std;
int rcalls = 0, adds = 0, muls = 0;

// Simple function to compute 10^k
long long power10(int k) {
    long long r = 1;
    while (k--) 
    r = r*10;
    return r;
}

// Count number of digits
int digits(long long x) {
    if (x == 0) 
    return 1;
    int c = 0;
    while (x > 0) {
        c++;
        x =x/ 10;
    }
    return c;
}

long long karatsuba(long long A, long long B) {
    rcalls++;

    // Base case (single digit)
    if (A < 10 && B < 10) {
        muls++;
        return A * B;
    }

    // Get maximum digit length
    int n = digits(A);
    int m = digits(B);
    int maxd = n > m ? n : m;

    int half = maxd / 2;

    long long p = power10(half);   // instead of pow(10, half)

    // Split A
    long long a1 = A / p;
    long long a2 = A % p;

    // Split B
    long long b1 = B / p;
    long long b2 = B % p;
    // Recursive calls
    long long P1 = karatsuba(a1, b1);
    long long P2 = karatsuba(a2, b2);

    adds++;
    long long A_sum = a1 + a2;

    adds++;
    long long B_sum = b1 + b2;

    long long P3 = karatsuba(A_sum, B_sum);

    // cross term
    adds += 2;
    long long cross = P3 - P1 - P2;

    // Final combine
    long long result =
        P1 * power10(2 * half) +
        cross * power10(half) +
        P2;

    return result;
}




int main() {
    long long A, B;
    cout << "Enter two large integers: ";
    cin >> A >> B;
    cout << "\nKaratsuba Result = " << karatsuba(A, B);
    cout << "\nRecursive Calls  = " << rcalls;
    cout << "\nMultiplications  = " << muls;
    cout << "\nAdditions        = " << adds;

    return 0;
}

