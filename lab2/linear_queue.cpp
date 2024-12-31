#include <iostream>
using namespace std;
#define MAX_SIZE 4

template <class T>
class Queue {
private:
    T qu[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enque(T x) {
        if (rear >= MAX_SIZE - 1) {
            cout << "The queue is full" << endl;
            return;
        }
        qu[++rear] = x;
    }

    T deque() {
        if (front > rear) {
            cout << "Queue is empty" << endl;
            return T();  // Return default-constructed value of type T
        }
        T item = qu[front++];
        return item;
    }

    void showqueue() {
        if (front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << qu[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> qu;
    qu.enque(0);
    qu.enque(1);
    qu.enque(2);
    qu.enque(3);
    qu.enque(4);

  
    qu.showqueue();

    qu.deque();
    qu.showqueue();

    return 0;
}
