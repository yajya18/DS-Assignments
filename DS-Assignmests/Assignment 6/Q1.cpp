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
    // void insertAtBeginning(int val){
    //     if(head==nullptr){
    //         Node* temp = new Node(val);
    //         head = temp;
    //         return;
    //     }
    //     Node* temp = new Node(val);
    //     temp->next = head;
    //     head = temp;
    // }
    CircularLL(){
        // next = head;
    }
    void insert(int data, int val){
        if(head->data==val){
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
            return;
        }
        Node* temp = head;
        while(temp->next->data!=val&&temp->next!=head){
            temp = temp->next;
        }
        if(temp->next==head){
            Node* nn = new Node(data);
            temp->next = nn;
            nn->next = head;
        }
        else{
            Node* nn = new Node(data);
            nn->next = temp->next;
            temp->next = nn;
        }
    }

    void deleteNode(int position){
        if(position==1){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for(int i=0;i<position-2;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp = temp->next;
        delete temp;
    }

    void Search(int position){
        Node* temp = head;
        for(int i=1;i<position;i++){
            temp = temp->next;
        }
        cout<<"The data value of the node at position "<<position<<" is "<<temp->data<<endl;
    }    
};

class DoublyLL{
public:
    Node* head = nullptr;
    void insert(int data, int val){
        if(head->data==val){
            Node* temp = new Node(data);
            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }
        Node* temp = head;
        while(temp->next->data!=val&&temp->next!=nullptr){
            temp = temp->next;
        }
        if(temp->next==nullptr){
            Node* nn = new Node(data);
            temp->next = nn;
            nn->prev = temp;
        }
        else{
            Node* nn = new Node(data);
            nn->next = temp->next;
            temp->next->prev=nn;
            temp->next = nn;
            nn->prev = temp;
        }
    }
    void deleteNode(int position){
        if(position==1){
            Node* temp = head;
            head = head->next;
            delete temp;
            head->prev = nullptr;
            return;
        }
        Node* temp = head;
        for(int i=0;i<position-2;i++){
            temp = temp->next;
        }
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
        temp = temp->next;
        delete temp;
    }
    void Search(int position){
        Node* temp = head;
        for(int i=1;i<position;i++){
            temp = temp->next;
        }
        cout<<"The data value of the node at position "<<position<<" is "<<temp->data<<endl;
    }
};

// int main(){
//     int input;
//     char choice;
//     int pos, val, data;
//     CircularLL c;
//     DoublyLL d;
//     cout<<"Enter 1 for circularLL operations and 2 for doublyLL operations: "<<endl;
//     cin>>input;
//     if(input==1){
//         cout<<"to insert enter 'i': "<<endl;
//         cout<<"To delete enter 'd': "<<endl;
//         cout<<"To Search enter 's': "<<endl;
//         cin>>choice;
//         switch (choice):
//             case 'i':
//                 cout<<"Enter the value before which you want to insert"<<endl;
//                 cin>>val;
//                 cout<<"Enter the data of the new node"<<endl;
//                 cin>>data;
//                 c.insert(data,val);
//                 break;
//             case 'd':
//     }
// }