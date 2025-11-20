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
    int size(){
        if(head == nullptr)return 0;
        int size=1;
        Node* temp = head;
        while(temp->next!=head){
            size++;
            temp=temp->next;
        }
        return size;
    }
};

class DoublyLL{
public:
    Node* head = nullptr;
    int size(){
        if(head == nullptr)return 0;
        int size = 1;
        Node* temp = head;
        while(temp->next!=nullptr){
            size++;
            temp = temp->next;
        }
        return size;
    }
};