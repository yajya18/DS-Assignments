class Node{
    public:
    int data;
    Node* next;
};

Node* findIntersectionNode(Node* &head1, Node* &head2){
    if(head1==nullptr||head2==nullptr) return nullptr   ;

    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=temp2){
        temp1 = (temp1 == nullptr) ? head2 : temp1->next;
        temp2 = (temp2 == nullptr) ? head1 : temp2->next;
    }
    return temp1;
}