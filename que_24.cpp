#include <iostream>
using namespace std;

long long moves = 0;

void hanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << src << " to " << dest << "\n";
        ++moves;
        return;
    }
    hanoi(n-1, src, aux, dest);
    cout << "Move disk " << n << " from " << src << " to " << dest << "\n";
    ++moves;
    hanoi(n-1, aux, dest, src);
}

int main() {
    int n = 3;
    cout << "Tower of Hanoi (n=" << n << "):\n";
    hanoi(n, 'A', 'C', 'B');
    cout << "Total moves: " << moves << "\n";
    return 0;
}