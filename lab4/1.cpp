/*
    IMPLEMENT STACK AS LINKED LIST
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *Next;
} typedef Node;

class Stack
{
private:
    Node *top = nullptr;

public:
    void push(int d)
    {
        Node *newNode = new Node();
        newNode->data = d;
        newNode->Next = top;
        top = newNode;
    }
    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty";
            return 0;
        }
        Node *temp = top;
        int popped = temp->data;
        top = top->Next;
        delete temp;
        return popped;
    }
    int peek()
    {
        return top->data;
    }
};

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top: " << stack.peek() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Top: " << stack.peek() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Top: " << stack.peek() << endl;
    return 0;
}