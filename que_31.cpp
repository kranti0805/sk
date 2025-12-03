#include <iostream>
using namespace std;

struct Item { int val, priority; };

class PriorityQueue {
    Item arr[100];
    int size;
public:
    PriorityQueue() { size = 0; }
    
    void insert(int val, int pr) {
        arr[size].val = val;
        arr[size].priority = pr;
        ++size;
        cout << "Inserted: value=" << val << ", priority=" << pr << "\n";
    }
    
    void deleteMax() {
        if (size == 0) { 
            cout << "Queue is empty\n"; 
            return; 
        }
        int maxIdx = 0;
        for (int i = 1; i < size; ++i) {
            if (arr[i].priority > arr[maxIdx].priority) maxIdx = i;
        }
        cout << "Deleted (max priority): value=" << arr[maxIdx].val << ", priority=" << arr[maxIdx].priority << "\n";
        for (int i = maxIdx; i < size-1; ++i) arr[i] = arr[i+1];
        --size;
    }
    
    void deleteMin() {
        if (size == 0) { 
            cout << "Queue is empty\n"; 
            return; 
        }
        int minIdx = 0;
        for (int i = 1; i < size; ++i) {
            if (arr[i].priority < arr[minIdx].priority) minIdx = i;
        }
        cout << "Deleted (min priority): value=" << arr[minIdx].val << ", priority=" << arr[minIdx].priority << "\n";
        for (int i = minIdx; i < size-1; ++i) arr[i] = arr[i+1];
        --size;
    }
    
    void display() {
        if (size == 0) { 
            cout << "Queue is empty\n"; 
            return; 
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < size; ++i) {
            cout << "(" << arr[i].val << "," << arr[i].priority << ") ";
        }
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;
    int choice, val, pr;
    
    while (true) {
        cout << "\n===== PRIORITY QUEUE =====\n";
        cout << "1. Insert element\n";
        cout << "2. Delete highest priority\n";
        cout << "3. Delete lowest priority\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 5) break;
        
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter priority: ";
            cin >> pr;
            pq.insert(val, pr);
        }
        else if (choice == 2) {
            pq.deleteMax();
        }
        else if (choice == 3) {
            pq.deleteMin();
        }
        else if (choice == 4) {
            pq.display();
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    cout << "Program ended.\n";
    return 0;
}