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

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtHead(head, 12);
    print(head);
    InsertAtTail(tail, 15);
    print(head);

    insertAtPosition(head,2,5);
    print(head);

    deletePosition(head, 2);
    print(head);
    
    return 0;
}


// #include <iostream>
// using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;
//     Node(int d){
//         this->next = nullptr;
//         this->data = d;
//     }
//     ~Node(){
//         if(this->next!=nullptr){
//             delete next;
//             this->next=nullptr;
//         }
//     }
// };

// void insertAtHead(Node* &head, int d){
//     Node* temp = new Node(d);
//     temp->next = head->next;
//     head = temp;
// }

// void insertAtTail(Node* &tail, int d){
//     Node* temp = new Node(d);
//     tail->next = temp;
//     temp->next = nullptr;
//     tail = tail->next;
// }

// void insertAtPosition(Node* &head, int position, int d){
//     Node* temp = head;
//     for(int i=1;i<position;i++){
//         temp = temp->next;
//     }
//     Node* node = new Node(d);
//     temp->next = node;
//     node->next = temp->next->next;
//     delete temp;
// }

// void print(Node* &head){
//     Node* temp=head;
//     while(temp->next!=nullptr){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }

// void deleteHead(Node* &head){
//     Node* temp = head;
//     head = head -> next;
//     delete temp;
// }

// void deleteTail(Node* &head, Node* &tail){
//     // Node* temp = head;
//     // while(temp->next!=nullptr){
//     //     temp = temp->next;
//     // }
//     // temp->next = nullptr;
//     // tail = temp;
//     Node* prev = nullptr;
//     Node* curr = head;
//     while(curr!=nullptr){
//         prev= curr;
//         curr = curr->next;
//     }
//     prev->next = nullptr;
//     delete curr;
// }

// void deleteAtPosition(Node* &head, int position){
//     if (position == 1) deleteHead(head);
//     else{
//         Node* prev = nullptr;
//         Node* curr = head;
//         for(int i=1;i<position;i++){
//             prev = curr;
//             curr = curr -> next;
//         }
//         prev -> next = curr->next;
//         delete curr;
//     }
// }

// int main() {
//     return 0;
// }



// doubly linked list
// #include <iostream>
// using namespace std;
// class dsa{
// public:
// dsa* ll;
// dsa* node;
// dsa* stack;
// };
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node* prev;
//     Node(int d){
//         next = nullptr;
//         prev = nullptr;
//         data = d;
//     }
// };

// void insertAtHead(Node* &head, int d){
//     Node* temp = head;
//     Node* node = new Node(d);
//     temp->prev = node;
//     node->next = temp;
//     head=temp->prev;
// }

// void insertAtTail(Node* &tail, int d){
//     Node* temp = tail;
//     Node* node = new Node(d);
//     temp->next = node;
//     node->prev = temp;
//     tail = node;
// }

// void insertAtPosition(Node* &tail, Node* &head, int d, int position){
//     Node* temp = head;
//     Node* node = new Node(d);
//     for(int i=1;i<position-1;i++){
//         if(temp->next==nullptr){
//             insertAtTail(tail, d);
//             return;
//         }
//         temp = temp->next;
//     }
//     node->next = temp->next;
//     temp->next = node;
//     node->prev = temp;
//     temp->next->prev = node;
// }

// void deletePosition(Node* &tail, Node* &head, int position){
//     if(position==1){
//         Node* temp = head;
//         if(head!=nullptr) head->prev=nullptr;
//         else tail=nullptr;
//         delete temp;
//         return;
//     }
//     else{
//         Node* curr = head;
//         Node* prev = nullptr;
//         for(int i=1;i<position;i++){
//             prev = curr;
//             curr = curr->next;
//         }
//         if(curr->next==nullptr){
//             tail = tail->prev;
//         }
//         prev->next = curr->next;
//         curr->next->prev = prev;
//         delete curr;
//     }
// }

// void print(Node* &head){
//     Node* temp = head;
//     while(temp!=nullptr){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }

// void deleteByValue(Node* &tail, Node* &head, int val){
//     Node* temp = head;
//     while(temp!=nullptr){
//         if(temp->data==val){
//             temp->prev->next = temp->next;
//             temp->next->prev = temp->prev;
//         }
//         temp = temp->next;        
//     }
//     delete temp;
// }

// void occurences(Node* tail, Node* head, int key){
//     Node* temp = head;
//     int count = 0;
//     while(temp!=nullptr){
//         if(temp->data == key){
//             count++;
//         }
//         temp = temp->next;
//     }
//     cout<<"Total no. of occurences of "<<key<<" are "<<count;
//     deleteByValue(tail,head,key);
// }

// int getlength(Node* &head){
//     Node* temp = head;
//     int len = 0;
//     while(temp!=nullptr){
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }

// void reverse(Node* &head, Node* &tail){
//     Node* curr;
//     Node* prev;
//     Node* temp;
//     while(head!=nullptr){
//         curr = head;
//         prev = tail;
//         temp = curr;
//         curr = prev;
//         prev = temp;

//         head = head->next;
//         tail = tail->prev;
//     }
//     delete temp;
// }

// int main() {
//     Node* node1 = new Node(1);
//     Node* head = node1;
//     Node* tail = node1;
//     insertAtHead(head, 9);
//     insertAtPosition(tail,head,5,2);
//     insertAtTail(tail,11);
//     insertAtPosition(tail, head, 2, 4);
//     // insertAtTail(tail,1);
//     // insertAtTail(tail,2);
//     // insertAtTail(tail,1);
//     // insertAtTail(tail, 2);
//     // insertAtTail(tail, 1);
//     // insertAtTail(tail, 3);
//     // insertAtTail(tail, 1);
//     // print(head);
//     // occurences(tail,head,1);
//     print(head);
//     reverse(head, tail);
//     print(head);

//     return 0;
// }



// #include <iostream>
// using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;
//     Node(int d){
//         this->next = nullptr;
//         this->data = d;
//     }
// };

// void print(Node* &head){
//     Node* temp = head;
//     while(temp!=nullptr){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<endl;
// }

// int getlength(Node* &head){
//     Node* temp = head;
//     int len = 0;
//     while(temp!=nullptr){
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }

// void insertAtTail(Node* &tail, int d){
//     Node* temp = new Node(d);
//     tail->next = temp;
//     temp->next = nullptr;
//     tail = tail->next;
// }

// int main() {
//     Node* node1 = new Node(1);
//     Node* head = node1;
//     Node* tail = node1;
//     insertAtTail(tail, 2);
//     insertAtTail(tail, 3);
//     insertAtTail(tail, 4);
//     insertAtTail(tail, 4);
//         Node* curr = head;
//         Node* prev = nullptr;
//         int count=0;
//         int c1=0;
//         int i=1;
//     do{
//         int a = curr->data;
//         for(int j=0;j<i;j++){
//             curr = curr->next;
//         }
//         if(c1 == 0 && curr->next == nullptr){
//             break;
//         }
//         while(curr->next!=nullptr){
//             prev = curr;
//             curr = curr->next;
//             if(curr->data==a){
//                 prev->next = curr->next;
//                 curr->next = nullptr;
//                 delete curr;
//                 c1++;
//             }
//         }
//         i++;
//         count++;
//     }while(true);

//     print(head);
//     return 0;
// }
