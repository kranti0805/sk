//Q4]Write a program to implement a greedy algorithm to solve a real-world 
//optimization problem, such as maximizing non-overlapping events in a scheduler (activity selection). 
//Represent the logic using pseudo-code and a flowchart. Analyse the algorithm's time complexity (Best, Average, Worst Case) using Big-O, Θ, and Ω notations.
#include <iostream>
using namespace std;

void sortByFinish(int start[], int finish[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (finish[j] > finish[j+1]) {
                int temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;

                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int start[50], finish[50];

    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++) 
    cin >> start[i];

    cout << "Enter finish times:\n";
    for (int i = 0; i < n; i++) 
    cin >> finish[i];

    sortByFinish(start, finish, n);

    int count = 1;
    int last = 0;

    for (int i = 1; i < n; i++) {
        if (start[i] >= finish[last]) {
            count++;
            last = i;
        }
    }

    cout << "Maximum events you can attend = " << count;
    return 0;
}
