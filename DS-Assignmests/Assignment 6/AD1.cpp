#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    Node* head;
    int data;
    Node(int data){
        this->data = data;
        next = nullptr;
        head = nullptr;
    }
};

int main() {
    return 0;
}