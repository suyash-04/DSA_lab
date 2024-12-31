/*
    REPRESENT THE POLYNOMIAL EQUATION USING LINKED LIST TO PERFORM
    ADDITION OF TWO POLYNOMIALS.
*/

#include <iostream>
using namespace std;

struct Node
{
    int coefficient;
    int exponent;
    Node *next;
    Node(int c, int e) : coefficient(c), exponent(e), next(nullptr) {}
};

class Polynomial
{
private:
    Node *head;

public:
    Polynomial() : head(nullptr) {}

    // Method to insert a term into the polynomial
    void insertTerm(int coefficient, int exponent)
    {
        Node *newNode = new Node(coefficient, exponent);
        if (!head)
        { // If the list is empty, initialize it
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            { // Traverse to the end of the list
                temp = temp->next;
            }
            temp->next = newNode; // Append the new node
        }
    }

    // Method to add two polynomials
    Polynomial add(const Polynomial &other) const
    {
        Polynomial result;
        Node *poly1 = head;
        Node *poly2 = other.head;

        while (poly1 || poly2)
        {
            if (poly1 && (!poly2 || poly1->exponent > poly2->exponent))
            {
                result.insertTerm(poly1->coefficient, poly1->exponent);
                poly1 = poly1->next;
            }
            else if (poly2 && (!poly1 || poly2->exponent > poly1->exponent))
            {
                result.insertTerm(poly2->coefficient, poly2->exponent);
                poly2 = poly2->next;
            }
            else
            {
                int sum = poly1->coefficient + poly2->coefficient;
                if (sum != 0)
                {
                    result.insertTerm(sum, poly1->exponent);
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }

        return result;
    }

    // Method to display the polynomial
    void display() const
    {
        if (!head)
        {
            cout << "0" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp)
                cout << " + ";
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Polynomial()
    {
        Node *temp = head;
        while (temp)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    Polynomial poly1, poly2;

    // Polynomial 1: 5x^3 + 4x^2 + 2x^0
    poly1.insertTerm(5, 3);
    poly1.insertTerm(4, 2);
    poly1.insertTerm(2, 0);

    // Polynomial 2: 3x^3 + 1x^1 + 2x^0
    poly2.insertTerm(3, 3);
    poly2.insertTerm(1, 1);
    poly2.insertTerm(2, 0);

    cout << "Polynomial 1: ";
    poly1.display();

    cout << "Polynomial 2: ";
    poly2.display();

    // Add polynomials
    Polynomial result = poly1.add(poly2);

    cout << "Resultant Polynomial: ";
    result.display();

    return 0;
}