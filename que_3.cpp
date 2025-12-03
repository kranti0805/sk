//Greedy Algorithm – Minimize Currency Notes in a Digital Wallet
#include <iostream>
using namespace std;

int main() {
    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    int coins[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n = 10;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (amount >= coins[i]) {
            int notes = amount / coins[i];
            count =count + notes;
            amount = amount % coins[i];
        }
    }
  cout << "Minimum notes/coins required = " << count << endl;
    return 0;
}
