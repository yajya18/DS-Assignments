#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node* fro;
    Node* rear;
    public:
    Node(): next(nullptr), fro(nullptr), rear(nullptr){}
    Node(int va): data(va), next(nullptr), fro(nullptr), rear(nullptr){}

    void enqueue(int x){
        if(fro == nullptr && rear == nullptr){
            Node* nn = new Node(x);
            fro = nn;
            rear = nn;
            return;
        }
        Node* nn = new Node(x);
        rear->next = nn;
        rear = rear->next;
    }

    void dequeue(){
        if(fro!=nullptr) fro = fro->next;
        else cout<<"There is no element in the queue to dequeue."<<endl;
    }

    inline void front(){
        if(fro!=nullptr) cout<<fro->data<<endl;
    }

    inline bool isEmpty() {
        return (fro == nullptr && rear == nullptr);
    }

    void printQueue(){
        Node* temp = fro;
        while(temp!=nullptr){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
};

int main() {
    Node q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    // q.front();
    q.printQueue();
    return 0;
}