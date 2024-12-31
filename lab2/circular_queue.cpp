#include <iostream>
using namespace std;
#define MAX_SIZE 4

template <class T>
class Queue{
    private:
        T qu[MAX_SIZE];
        int front , rear;
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        bool isEmpty(){
            return (front == -1);
    
        }
        bool isFull(){
            return (((rear+1)% MAX_SIZE) == front);
        }

        void enqueue(T x){
            if(isFull()){
                cout << "queue is full"<<endl;
                return ;
            }

            if(isEmpty()){
                front = 0; 
                rear = 0;
            }
            else {
            rear = (rear+1)% MAX_SIZE ;

            }
            qu[rear ] = x;


        }
        void dequeue(){
            if(isEmpty()){
                cout<<"queue is empty"<<endl;
                return ;
            }
            T item = qu[front];
            if (front == rear){
                front = -1 ;
                rear = -1;
            }else {
                front = (front +1)%MAX_SIZE;
              }
            cout <<"removed"<<item<<endl;
        }
        void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << qu[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};
int main(){
  Queue <int> cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);  // Queue is now full

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();
}