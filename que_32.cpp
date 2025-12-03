#include <iostream>
using namespace std;

const int MAX = 100;

class Deque {
    int arr[MAX], front, rear;
public:
    Deque() { front = -1; rear = -1; }
    
    void insertFront(int val) {
        if (front == 0) { 
            cout << "Overflow\n"; 
            return; 
        }
        if (front == -1) front = rear = 0;
        else front--;
        arr[front] = val;
        cout << "Inserted at front: " << val << "\n";
    }
    
    void insertRear(int val) {
        if (rear == MAX-1) { 
            cout << "Overflow\n"; 
            return; 
        }
        if (rear == -1) front = rear = 0;
        else rear++;
        arr[rear] = val;
        cout << "Inserted at rear: " << val << "\n";
    }
    
    void deleteFront() {
        if (front == -1) { 
            cout << "Underflow\n"; 
            return; 
        }
        cout << "Deleted from front: " << arr[front] << "\n";
        if (front == rear) front = rear = -1;
        else front++;
    }
    
    void deleteRear() {
        if (rear == -1) { 
            cout << "Underflow\n"; 
            return; 
        }
        cout << "Deleted from rear: " << arr[rear] << "\n";
        if (front == rear) front = rear = -1;
        else rear--;
    }
    
    void display() {
        if (front == -1) { 
            cout << "Deque is empty\n"; 
            return; 
        }
        cout << "Deque: ";
        for (int i = front; i <= rear; ++i) cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Deque dq;
    int choice, val;
    
    while (true) {
        cout << "\n===== DEQUE =====\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 6) break;
        
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            dq.insertFront(val);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            dq.insertRear(val);
        }
        else if (choice == 3) {
            dq.deleteFront();
        }
        else if (choice == 4) {
            dq.deleteRear();
        }
        else if (choice == 5) {
            dq.display();
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}