#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val){
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};

class CircularLL{
public:
    Node* head = nullptr;
    void display(){
        cout<<head->data<<"\t";
        Node* temp = head->next;
        while(temp!=head){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
    }
};