#include <iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int data;
        Node(){}
        Node(int d){
            this->next = nullptr;
            this->data = d;
        }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtPosition(Node* &head, int position, int d){
    Node* temp = head;
    if(position == 1)insertAtHead(head, d);
    for(int i=0;i<position-1;i++){
        temp = temp -> next;
    }
    Node* node = new Node(d);
    node->next = temp->next;
    temp->next = node;
    
}

void deleteHead(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteTail(Node* &tail){
    Node* temp = tail;
}

void deletePosition(Node* &head, int position){
    if(position == 1)deleteHead(head);
    else{
        Node* prev = NULL;
        Node* curr = head;
        for(int i=1;i<position;i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }  
}

void reverseLinkedList(Node* &head){
    Node* curr = head;
    Node* prev = nullptr;
    while(curr!=nullptr){
        Node* forward = curr->next;
        curr->next = prev;
        prev=curr;
        curr = forward;
    }
    head = prev;
}

void deleteByValue(Node* &tail, Node* &head, int val){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->next->data==val){
            temp->next->next=nullptr;
            temp->next = temp->next->next;
        }
        temp = temp->next;        
    }
    delete temp;
}

void occurences(Node* tail, Node* head, int key){
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr){
        if(temp->data == key){
            count++;
        }
        temp = temp->next;
    }
    cout<<"Total no. of occurences of "<<key<<" are "<<count;
    deleteByValue(tail,head,key);
}