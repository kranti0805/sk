#include <iostream>
using namespace std;

const int MAX = 5;

class CircQueue {
    int arr[MAX], front, rear;
public:
    CircQueue() { front = rear = -1; }
    
    void enqueue(int val) {
        if ((rear+1) % MAX == front) { 
            cout << "Overflow\n"; 
            return; 
        }
        rear = (rear+1) % MAX;
        arr[rear] = val;
        if (front == -1) front = 0;
        cout << "Enqueued: " << val << "\n";
    }
    
    void dequeue() {
        if (front == -1) { 
            cout << "Underflow\n"; 
            return; 
        }
        cout << "Dequeued: " << arr[front] << "\n";
        if (front == rear) { 
            front = rear = -1; 
            return; 
        }
        front = (front+1) % MAX;
    }
    
    void display() {
        if (front == -1) { 
            cout << "Queue is empty\n"; 
            return; 
        }
        cout << "Queue: ";
        int i = front;
        do { 
            cout << arr[i] << " "; 
            i = (i+1) % MAX; 
        } while (i != (rear+1) % MAX);
        cout << "\n";
    }
};

int main() {
    CircQueue q;
    int choice, val;
    
    while (true) {
        cout << "\n===== CIRCULAR QUEUE =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 4) break;
        
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.display();
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}