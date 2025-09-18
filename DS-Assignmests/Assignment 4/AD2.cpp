#include <iostream>
#define MAX 100
using namespace std;

class Queue {
public:
    int front, rear;
    int q[MAX];

    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int val) {
        if (rear == MAX - 1) return; 
        if (isEmpty()) front = 0;
        q[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        return q[front++];
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    void display() {
        if (isEmpty()) return;
        for (int i = front; i <= rear; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

void sortQueue(Queue &Q) {
    int n = Q.size();
    for (int i = 0; i < n; i++) {
        int minVal = 9999;

        for (int j = 0; j < n - i; j++) {
            int x = Q.dequeue();
            if (x < minVal) minVal = x;
            Q.enqueue(x);
        }

        bool skipped = false;
        for (int j = 0; j < n; j++) {
            int x = Q.dequeue();
            if (x == minVal && !skipped && j < n - i) {
                skipped = true; 
            } else {
                Q.enqueue(x);
            }
        }

        Q.enqueue(minVal);
    }
}

int main() {
    Queue q;
    q.enqueue(30);
    q.enqueue(11);
    q.enqueue(15);
    q.enqueue(4);

    cout << "Original queue: ";
    q.display();

    sortQueue(q);

    cout << "Sorted queue: ";
    q.display();

    return 0;
}
