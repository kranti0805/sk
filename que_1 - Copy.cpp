//gauss multiplication

#include <iostream>
using namespace std;

int rcalls = 0, adds = 0, muls = 0;

int gauss(int A, int B) {
    rcalls++;

    // Base case: single digit
    if (A < 10 && B < 10) {
        muls++;
        return A * B;
    }

    // Split digits
    int a1 = A / 10;
    int a2 = A % 10;

    int b1 = B / 10;
    int b2 = B % 10;

    // Recursively calculate
    int P1 = gauss(a1, b1);
    int P2 = gauss(a2, b2);
    adds++;
  int A_sum = a1 + a2;
    adds++;
    int B_sum = b1 + b2;

    int P3 = gauss(A_sum, B_sum);

    // cross = P3 - P1 - P2
    adds += 2;
    int cross = P3 - P1 - P2;

    int result = P1 * 100 + cross * 10 + P2;
    return result;
}
int main() {
    int A, B;
    cout << "Enter two 2-digit numbers: ";
    cin >> A >> B;
    int ans = gauss(A, B);
    cout << "\nGauss Multiplication Result = " << ans;
    cout << "\nRecursive Calls = " << rcalls;
    cout << "\nMultiplications = " << muls;
    cout << "\nAdditions = " << adds;
    return 0;
}

//Recursive Calls = 3
//Multiplications = 3
//Additions = 4