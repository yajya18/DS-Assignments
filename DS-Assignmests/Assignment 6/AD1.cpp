// #include <iostream>
// using namespace std;

// class Node{
// public:
//     Node* next;
//     Node* head;
//     int data;
//     Node(int data){
//         this->data = data;
//         next = nullptr;
//         head = nullptr;
//     }
// };

// class CircularLL{
//     int getlength(Node* &head){
//         Node* temp = head->next;
//         int count = 1;
//         while(temp!=head){
//             temp = temp->next;
//             count++;
//         }
//         return count;
//     }
//     void split(Node* &head){
//         int count = getlength(head);
//         Node* temp = head;
//         if(count%2==0){
//             for(int i=0;i<count/2-1;i++) temp = temp->next;
//             Node* head2 = temp->next;
//             temp->next = head;
//             Node* temp2 =head2;
//             while(temp2->next!=head)temp2=temp2->next;
//             temp2->next=head2;
//             return;
//         }
//         for(int i=0;i<count/2;i++) temp = temp->next;
//         Node* head2 = temp->next;
//         temp->next = head;
//         Node* temp2 =head2;
//         while(temp2->next!=head)temp2=temp2->next;
//         temp2->next=head2;
//     }
// };

// int main() {
//     return 0;
// }


#include <iostream>
using namespace std;

class CircularLL{
    int data;
    CircularLL* next;
    
    public:
    CircularLL(int val): data(val), next(nullptr){}

    int getlength(CircularLL* &head){
        if(head==nullptr)return 0;
        int count;
        CircularLL* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void split(CircularLL* &head, CircularLL* &head2){
        int c = getlength(head);
        CircularLL* tail1;
        CircularLL* temp = head;
        if(c%2){
            for(int i=0;i<c/2;i++)temp = temp->next;
            tail1 = temp;
            tail1->next = head;
            temp = temp->next;
            head2 = temp;
            while(temp->next)temp=temp->next;
            temp->next = head2;
        }
    }
};

int main() {
    return 0;
}