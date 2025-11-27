#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int v) {
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLL {
private:
    Node* head;

    int countOnes(int n) {
        int c = 0;
        while (n) {
            c += (n & 1);
            n >>= 1;
        }
        return c;
    }

    bool isEvenParity(int n) {
        return (countOnes(n) % 2 == 0);
    }

public:
    DoublyLL() {
        head = NULL;
    }

    void insert(int v) {
        Node* node = new Node(v);
        if (head == NULL) {
            head = node;
            return;
        }

        Node* cur = head;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = node;
        node->prev = cur;
    }

    void removeEvenParity() {
        Node* cur = head;

        while (cur != NULL) {
            Node* nxt = cur->next;

            if (isEvenParity(cur->val)) {
                if (cur->prev)
                    cur->prev->next = cur->next;
                else
                    head = cur->next;

                if (cur->next)
                    cur->next->prev = cur->prev;

                delete cur;
            }

            cur = nxt;
        }
    }

    void print() {
        Node* cur = head;
        if (!cur) {
            cout << "List is empty\n";
            return;
        }
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

// ------------------------ MAIN FUNCTION ------------------------
int main() {
    return 0;
}
