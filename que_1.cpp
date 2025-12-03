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

1)	Write a program to implement Gauss’s multiplication method. Display the number of recursive calls, multiplications, and additions are required to implement this method.
2)	Write a program to implement Karatsuba’s algorithm for multiplying large integers. Display the number of recursive calls, multiplications, and additions are required to implement this method.
3)	Write a program to implement a greedy algorithm to solve a real-world optimization problem, such as minimizing currency notes in a digital wallet (coin change). write the logic using pseudo-code and a flowchart. Analyse the algorithm's time complexity (Best, Average, Worst Case) using Big-O, Θ, and Ω notations.
4)	Write a program to implement a greedy algorithm to solve a real-world optimization problem, such as maximizing non-overlapping events in a scheduler (activity selection). Represent the logic using pseudo-code and a flowchart. Analyse the algorithm's time complexity (Best, Average, Worst Case) using Big-O, Θ, and Ω notations.
5)	Write a program to Implement basic array operations such as insert, delete, and merge, while simulating a 2D array using a single-dimensional array to optimize space (using both row-major and column-major formats). Use pointer arithmetic to print memory addresses of elements, helping you understand how arrays are stored in memory.
6)	Write a program to implement simple transpose and fast transpose of a sparse matrix using the 3-tuple representation. Compare both methods based on their time and space efficiency to understand which one works better for handling large and fragmented data in real-world systems.
7)	Write a program to perform addition of two sparse matrices using the 3-tuple representation. Analyse the time and space complexity of your program and explain why efficient sparse matrix addition is useful for large data sets where most values are zero.
8)	Write a program to Implement polynomial addition and multiplication operations using array representation. 
9)	Write a program to store a polynomial using an array of structures, where each structure contains a coefficient and an exponent. Perform polynomial addition and multiplication using this structure-based representation. Compare the efficiency of this approach with the previous method and explain which representation is better and why.
10)	Write a menu-driven program to implement and compare different search techniques — Linear, Sentinel Search — on sorted and unsorted datasets. Count and display the number of comparisons made by each algorithm to evaluate their efficiency.
11)	Write a menu-driven program to implement and compare different search techniques — Binary, and Fibonacci Search — on sorted and unsorted datasets. Count and display the number of comparisons made by each algorithm to evaluate their efficiency.
12)	Write a program to implement Bubble, Insertion Sort to analyse their performance on the same input array. Track and display the time taken, number of swaps, and comparisons, and generate a report with the sorted output and performance insights. 
13)	Write a program to implement Shell Sort & Radix Sort to analyse their performance on the same input array. Track and display the time taken, number of swaps, and comparisons, and generate a report with the sorted output and performance insights. 
14)	Write a program to implement Quick Sort Track and display the time taken, number of swaps, and comparisons, and generate a report with the sorted output and performance insights. 
15)	Write a program to perform addition of polynomials using singly linked list.
16)	 Write a program to implement Generalized Linked List (GLL). 
17)	Write a program to implement a singly linked list and perform the following operations: Insert a node at the beginning, end, and at a specific position, delete a node from the beginning, end, and a specific position, Search for an element in the linked list, Display the linked list
18)	Write a program to implement a linked-list-based Music Playlist Manager.
Your program should allow users to: Add a new song, delete a song, move to the next or previous song, Display the current playlist. Explain why a linked list is better than an array for this application (dynamic size, fast insert/delete).
19)	Write a program to implement a Doubly Linked List (DLL). Your program should support the following operations: Insert a node at the beginning, at the end, and at any given position, delete a node from the beginning, from the end, and from any given position, display the list in forward and reverse order, search for an element in the list. Also analyse how DLL helps in easier forward–backward navigation compared to a singly linked list. 
20)	Write a program to implement a Circular Linked List (CLL). Your program should include the following operations: Insert a node at the beginning and at the end, delete a node from the beginning and from the end, Traverse and display all elements of the circular list, Search for an element in the circular list.
21)	Write a program to convert Infix Expression into Postfix Expression. Ensure your implementation handles parentheses, multi-digit operands, and input errors gracefully.
22)	Write a program to convert Infix Expression into Prefix Expression. Ensure your implementation handles parentheses, multi-digit operands, and input errors gracefully.
23)	Write a program to Evaluate Postfix Expression.
24)	Write a program to implement Tower of Hanoi using Recursion.
25)	Write a program to implement Tower of Hanoi using explicit stack.
26)	Write a program to implement Factorial using Recursion.
27)	Write a program to implement Factorial using explicit stack.
28)	Write a program to implement a Linear Queue using an array.
The program should support the following operations: Enqueue (Insert element), Dequeue (Delete element), Peek (Display front element), Display (Show all elements in the queue), Also, handle overflow and underflow conditions properly.
29)	Write a program to implement a Circular Queue using an array and perform the operations: Enqueue, Dequeue, Peek, Display, compare how Circular Queue avoids the limitations of Linear Queue.
30)	Write a program to implement a Queue using a singly linked list. Implement the following functions: Enqueue, Dequeue, Display Explain how a linked list avoids overflow issues seen in array implementation.
31)	Write a program to implement a Priority Queue where each element has a priority value.
The program should always delete the element with the highest or lowest priority (based on your choice). Support insert, delete, and display operations.
32)	Write a program to implement a Double-Ended Queue (Deque). Allow insertion and deletion at both front and rear. Implement the following operations: Insert Front, Insert, Rear, Delete Front, Delete Rear, Display.
33)	Write a program to simulate a Queue-based system such as: Printer Spooling, Ticket Counter, Traffic Management, use a queue to model real-world waiting-line behaviour and display how requests are processed in order.

