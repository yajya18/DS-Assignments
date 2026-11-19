#include <iostream>
using namespace std;

class Tree{
    int data;
    Tree* left;
    Tree* right;

    public:
    Tree(int val): data(val), left(nullptr), right(nullptr){}

    void insertNode(int x, Tree* &root){
        if(root==nullptr){
            Tree* nn = new Tree(x);
            root = nn;
            return;
        }
        if(x<root->data){
            if(root->left==nullptr){
                Tree* nn = new Tree(x);
                root->left=nn;
            }
            else if(root->left!=nullptr) insertNode(x, root->left);
        }
        else if(x>root->data){
            if(root->right==nullptr){
                Tree* nn = new Tree(x);
                root->right=nn;
            }
            else if(root->right!=nullptr) insertNode(x, root->right);
        }
    }

    void insertArray(int arr[], Tree* &root){
        
    }
};

int main() {
    return 0;
}