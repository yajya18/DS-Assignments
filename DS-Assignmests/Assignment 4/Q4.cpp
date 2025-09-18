#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

class Queue{
    public:
        int front, rear;
        int queue[MAX];

        Queue(){
            front = rear = -1;
        }
        int isFull(){
            return rear == MAX-1;
        }
        int isEmpty(){
            return (front == -1 || front > rear);
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
        char dequeue(){
            if(isEmpty()){
                cout<<"Underflow condition.\n";
                return -1;
            }
            int o = queue[front];
            if(front==rear){
                front = rear = -1;
            }
            else{
                front++;
            }
            return o;
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
        char peek(){
            if(isEmpty()){
                cout<<"The queue is empty.\n";
            }
            else{
                return queue[front];
            }
            
        }
        void clear(){
            front = rear = -1;
        }
};

int main() {
    Queue q;
    string str;
    cout<<"Enter the string: "<<endl;
    cin>>str;
    for(int i=0; i<str.length(); i++){
        q.enqueue(str[i]);
    }
    for(int i=0; i<str.length(); i++){
        char t = str[i];
        if(q.isEmpty()){
            break;
        }
        else{
            int count = 0;
            for(int j = 0; j<str.length(); j++){
                if(t==q.peek()){
                    q.dequeue();
                    count++;
                }
                else{
                    continue;
                }
                if(count == 2){
                    q.clear();
                    for(int k = 0; k<str.length(); k++){
                        q.enqueue(str[i]);
                    }
                    break;
                }
            }
            if(count != 2){
                cout<<t<<" ";
            }
            else{
                cout<<"-1 ";
            }
        }
    }
    return 0;
}