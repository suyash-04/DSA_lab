/*
    IMPLEMENT QUEUE AS LINKED LIST
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *Next;
} typedef Node;

class Queue
{
private:
    Node *front = nullptr;
    Node *rear = nullptr;

public:
    void enqueue(int d)
    {
        Node *newNode = new Node();
        newNode->data = d;
        newNode->Next = nullptr;

        if (front == nullptr && rear == nullptr)
        {
            front = newNode; // for first insertion
        }
        else
        {
            rear->Next = newNode;
        }
        rear = newNode;
    }

    int dequeue()
    {
        Node *temp = front;
        int popped;
        if (front == nullptr && rear == nullptr)
        {
            cout << "Queue is empty";
            return 0;
        }
        else
        {
            popped = front->data;
            if (front == rear) // single element
            {
                front = nullptr;
                rear = nullptr;
            }
            else
            {
                front = front->Next;
            }
            delete temp;
            return popped;
        }
    }

    int peek()
    {
        return front->data;
    }
};

int main()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Peek: " << queue.peek() << endl;
    return 0;
}