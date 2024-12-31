

#include <iostream>
using namespace std;

#define MAX_SIZE 5  // Define the maximum size of the deque

template <class T>
class Deque {
private:
    T arr[MAX_SIZE];
    int front, rear;

public:
    // Constructor to initialize the deque
    Deque() {
        front = -1;
        rear = -1;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if the deque is full
    bool isFull() {
        return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
    }

    // Insert at the front
    void insertFront(T value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the front." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }

        arr[front] = value;
        cout << "Inserted " << value << " at the front." << endl;
    }

    // Insert at the rear
    void insertRear(T value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the rear." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        cout << "Inserted " << value << " at the rear." << endl;
    }

    // Delete from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front." << endl;
            return;
        }

        cout << "Deleted " << arr[front] << " from the front." << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // Delete from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear." << endl;
            return;
        }

        cout << "Deleted " << arr[rear] << " from the rear." << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }

    // Display the elements in the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque<int> dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(3);

    dq.display();  // Output: 3 5 10 20

    dq.deleteFront();
    dq.display();  // Output: 5 10 20

    dq.deleteRear();
    dq.display();  // Output: 5 10

    dq.insertRear(15);
    dq.insertFront(2);
    dq.display();  // Output: 2 5 10 15

    return 0;
}
