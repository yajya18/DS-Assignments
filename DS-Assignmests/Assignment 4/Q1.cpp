#include <iostream>
#define MAX 10
using namespace std;

class Queue{
    public:
        int front, rear;
        int queue[MAX];
        
        int isFull(){
            return rear == MAX-1;
        }
        int isEmpty(){
            return (front==-1||rear==-1);
        }
        void enqueue(int val){
            if(isFull()){
                cout<<"Overflow condition\n";
            }
            else if(isEmpty()){
                this->front = this->rear = 0;
                queue[rear] = val;
            }
            else{
                queue[++rear] = val;
            }
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Underflow condition.\n";
            }
            else if(front>rear){
                front = rear = -1;
            }
            else{
                cout<<queue[front];
                front++;
            }
        }
        void display(){
            if(isEmpty()){
                cout<<"The queue is empty.\n";
            }
            else{
                for(int i=front;i<=rear;i++){
                cout<<queue[i]<<"\t";
                }
                cout<<endl;
            }
        }
        void peek(){
            if(isEmpty()){
                cout<<"The queue is empty.\n";
            }
            else{
                cout<<queue[front];
                cout<<endl;
            }
            
        }
};

int main(){
    int x,val;
    Queue q;
    q.front = q.rear = -1;
    while(true){
        cout<<"Enter the corresponding numbers for the following commands\n\n";
        cout<<"1) Enqueue\n";
        cout<<"2) Dequeue\n";
        cout<<"3) Display\n";
        cout<<"4) Peek\n";
        cin>>x;
        switch(x){
            case 1:
                cout<<"Enter the value: ";
                cin>>val;
                q.enqueue(val);
                cout<<endl;
                break;
            case 2:
                cout<<"Dequeued value is: ";
                q.dequeue();
                cout<<endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peek();
                break;
            default:
                cout<<"Enter a valid entry.\n";
                break;
        }
    }
return 0;
}