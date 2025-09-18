#include <iostream>
#define MAX 100
using namespace std;

class Queue{
    public:
    int queue[MAX];
    int front, rear;

    Queue(){
        front = rear = -1;
    }

    bool isEmpty(){
        return ((front == -1) && (rear == -1));
    }

    bool isFull(){
        return rear == MAX-1;
    }

    void enqueue(int val){
        if(isFull()){
            cout<<"Overflow condition.\n";
        }
        else if(isEmpty()){
            front = rear = 0;
            queue[rear] = val;
        }
        else{
            queue[++rear] = val;
        }
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Underflow condition.\n";
            return -1;
        }
        int h = queue[front];
        if(front==rear){
            front = rear = -1;
        }
        else{
            front++;
        }
        return h;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << "\t";
        }
        cout << endl;
        }
};

int main() {
    Queue q;
    for(int i=0;i<6;i++){
        q.enqueue(i+1);
    }
    Queue q1;
    for(int i=0;i<3;i++){
        q1.enqueue(q.dequeue());
    }
    for(int i=0;i<3;i++){
        q.enqueue(q1.dequeue());
        q.enqueue(q.dequeue());
    }
    q.display();
    return 0;
}