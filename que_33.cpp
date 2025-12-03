#include <iostream>
using namespace std;

#define SIZE 20   


struct Queue {
    int data[SIZE];
    int front;
    int rear;
};


void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
}


int isEmpty(Queue &q) {
    return (q.front == -1);
}


int isFull(Queue &q) {
    return ( (q.rear + 1) % SIZE == q.front );
}


void enqueue(Queue &q, int jobID) {
    if (isFull(q)) {
        cout << "\nSpooler Full! Cannot add more print jobs.\n";
        return;
    }

    if (isEmpty(q)) {
        q.front = 0;
        q.rear = 0;
    } else {
        q.rear = (q.rear + 1) % SIZE;
    }

    q.data[q.rear] = jobID;
    cout << "Print Job " << jobID << " added to spooler.\n";
}

// ----------- DEQUEUE (PROCESS PRINT JOB) -----------
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "\nNo print jobs to process.\n";
        return;
    }

    int jobID = q.data[q.front];

    if (q.front == q.rear) {  
        q.front = q.rear = -1;  
    } else {
        q.front = (q.front + 1) % SIZE;
    }

    cout << "Processing Print Job " << jobID << "...\n";
}

// ----------- DISPLAY PENDING JOBS -----------
void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "\nNo pending print jobs.\n";
        return;
    }

    cout << "\nPending Print Jobs: ";
    int i = q.front;

    while (true) {
        cout << q.data[i] << " ";
        if (i == q.rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

// ----------- MAIN FUNCTION -----------
int main() {
    Queue spooler;
    initQueue(spooler);

    int choice, jobID;

    while (1) {
        cout << "\n--- PRINTER SPOOLER SYSTEM ---\n";
        cout << "1. Add Print Job (ENQUEUE)\n";
        cout << "2. Process Print Job (DEQUEUE)\n";
        cout << "3. View Pending Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> jobID;
                enqueue(spooler, jobID);
                break;

            case 2:
                dequeue(spooler);
                break;

            case 3:
                display(spooler);
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}
