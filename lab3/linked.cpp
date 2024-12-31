
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *Next;
};

void insertAtBeginning(Node *&head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->Next = head;
    head = newNode;
}

void insertAtEnd(Node *&head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->Next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAfterSpecificNode(Node *head, int value, int data)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr && temp->data != value)
    {
        temp = temp->Next;
    }

    if (temp == nullptr)
    {
        cout << "Value not found" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void insertBeforeSpecificNode(Node *&head, int value, int data)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    if (head->data == value)
    {
        insertAtBeginning(head, data);
        return;
    }

    Node *temp = head;
    while (temp->Next != nullptr && temp->Next->data != value)
    {
        temp = temp->Next;
    }

    if (temp->Next == nullptr)
    {
        cout << "Value not found" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void deleteFromBeginning(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }
    Node *temp = head;
    head = head->Next;
    delete temp;
}

void deleteFromEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    if (head->Next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->Next->Next != nullptr)
    {
        temp = temp->Next;
    }
    delete temp->Next;
    temp->Next = nullptr;
}

void deleteSpecificNode(Node *&head, int value)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    if (head->data == value)
    {
        Node *temp = head;
        head = head->Next; 
        delete temp;      
        return;
    }

    Node *temp = head;
    while (temp->Next != nullptr && temp->Next->data != value)
    {
        temp = temp->Next;
    }

    if (temp->Next == nullptr)
    {
        cout << "Value not found" << endl;
        return;
    }

    Node *target = temp->Next;
    temp->Next = target->Next;
    delete target;
}

void displayList(Node *head)
{
    Node *traverse = head;
    while (traverse != nullptr)
    {
        cout << traverse->data << '\t';
        traverse = traverse->Next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    insertAtBeginning(head, 22);
    insertAtBeginning(head, 11);
    insertAtEnd(head, 44);
    insertBeforeSpecificNode(head, 44, 33);
    insertAfterSpecificNode(head, 33, 40);

    displayList(head);

    deleteFromEnd(head);
    deleteFromBeginning(head);
    deleteSpecificNode(head, 33);

    displayList(head);

    return 0;
}