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
    bool checkCircular(){
        if(head==nullptr)return false;
        Node* temp = head;
        while(temp!=nullptr||temp!=head){
            temp = temp->next;
        }
        if(temp == head) return true;
        else return false;
    }
};