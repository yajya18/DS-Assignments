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

class DoublyLL{
public:
    Node* head = nullptr;
    bool checkPalindrome(){
        if(head==nullptr) return false;
        int i=0;
        int j=0;
        vector<int> v1;
        vector<int> v2;
        Node* temp1 = head;
        Node* temp2 = head;
        while(temp2->next!=nullptr){
            temp2 = temp2->next;
        }
        while(temp1->next!=nullptr){
            v1[i]=temp1->data;
            temp1 = temp1->next;
            i++;
        }
        while(temp2!=head){
            v2[j]= temp2->data;
            temp2 = temp2->prev;
            j++;
        }
        if(v1==v2) return true;
        else return false;
    }
};