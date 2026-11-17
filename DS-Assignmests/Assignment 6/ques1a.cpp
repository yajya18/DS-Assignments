#include <iostream>
using namespace std;

class DoublyLL{
    int data;
    DoublyLL* next;
    DoublyLL* prev;

    public:
    DoublyLL(int data): data(data), next(nullptr), prev(nullptr){}

    void insertAtPostion(DoublyLL* &head, DoublyLL* &node, int val){
        if(head==nullptr)return;
        if(node==nullptr){
            DoublyLL* temp = head;
            while(temp->next!=nullptr)temp=temp->next;
            temp->next=new DoublyLL(val);
            temp->next->prev = temp;
            return;
        }
        DoublyLL* temp = head;
        while(temp->next!=node)temp= temp->next;
        temp->next = new DoublyLL(val);
        temp->next->prev = temp;
        temp->next->next = node;
        node->prev = temp->next;
    }
};

class CircularLL{
    int data;
    CircularLL* next;
    
};

int main() {
    return 0;
}