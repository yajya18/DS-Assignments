/*
 * ============================================================
 *  Sandhi151 | DSA Lab | Assignment 3
 *  Q2 : Singly Linked List – All Operations
 * ============================================================
 *  Operations:
 *   1.  insertAtEnd     - add node at end
 *   2.  display         - print all nodes
 *   3.  countAndSum     - count nodes and sum of values
 *   4.  search          - find a key in the list
 *   5.  deleteNode      - delete a node by value
 *   6.  isSorted        - check if list is sorted
 *   7.  mergeSorted     - merge two sorted linked lists
 *   8.  concatenate     - concatenate two linked lists
 *   9.  reverse         - reverse the linked list
 *   10. reorder         - reorder {A1,A2..An} -> {A1,An,A2,An-1..}
 *
 *  Memory: malloc used for every node allocation.
 * ============================================================
 */

#include <iostream>
#include <cstdlib>      // malloc, free
using namespace std;

/* ============================================================
   Node structure
   ============================================================ */
struct Node {
    int   data;
    Node* next;
};

/* ============================================================
   createNode  –  allocate a new node using malloc
   ============================================================ */
Node* createNode(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

/* ============================================================
   1. insertAtEnd
   ============================================================ */
void insertAtEnd(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

/* ============================================================
   2. display  –  print all elements
   ============================================================ */
void display(Node* head) {
    if (head == NULL) { cout << "  List is empty\n"; return; }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

/* ============================================================
   3. countAndSum  –  count nodes + sum of all values
   ============================================================ */
void countAndSum(Node* head, int& count, int& sum) {
    count = 0;
    sum   = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        sum += temp->data;
        temp = temp->next;
    }
}

/* ============================================================
   4. search  –  returns true if key is found
   ============================================================ */
bool search(Node* head, int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "  Found " << key << " at position " << pos << "\n";
            return true;
        }
        temp = temp->next;
        pos++;
    }
    cout << "  " << key << " not found in list\n";
    return false;
}

/* ============================================================
   5. deleteNode  –  delete first occurrence of val
   ============================================================ */
void deleteNode(Node*& head, int val) {
    if (head == NULL) { cout << "  List is empty\n"; return; }

    // If head itself holds the value
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
        cout << "  Deleted " << val << "\n";
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL) {
        if (curr->data == val) {
            prev->next = curr->next;
            free(curr);
            cout << "  Deleted " << val << "\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "  Value " << val << " not found\n";
}

/* ============================================================
   6. isSorted  –  check non-decreasing order
   ============================================================ */
bool isSorted(Node* head) {
    if (head == NULL || head->next == NULL) return true;
    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data) return false;
        temp = temp->next;
    }
    return true;
}

/* ============================================================
   7. mergeSorted  –  merge two sorted lists into one sorted list
   Returns the head of the merged list.
   ============================================================ */
Node* mergeSorted(Node* l1, Node* l2) {
    // dummy head makes logic simpler
    Node dummy;
    dummy.data = 0;
    dummy.next = NULL;
    Node* tail = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    // attach remaining nodes
    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
}

/* ============================================================
   8. concatenate  –  attach list2 at the end of list1
   ============================================================ */
void concatenate(Node*& head1, Node* head2) {
    if (head1 == NULL) { head1 = head2; return; }
    Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
}

/* ============================================================
   9. reverse  –  reverse the linked list in-place
   ============================================================ */
void reverse(Node*& head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next       = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }
    head = prev;
}

/* ============================================================
   10. reorder
   Reorder {A1, A2, ... An-1, An}
        to {A1, An, A2, An-1, ...}  WITHOUT extra space.

   Steps:
   a. Find the middle of the list.
   b. Reverse the second half.
   c. Interleave the two halves.
   ============================================================ */
void reorder(Node*& head) {
    if (head == NULL || head->next == NULL) return;

    // --- step a: find middle using slow/fast pointers ---
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is now at the middle

    // --- step b: reverse second half ---
    Node* secondHalf = slow->next;
    slow->next = NULL;          // cut list in two

    Node* prev = NULL;
    Node* curr = secondHalf;
    Node* next = NULL;
    while (curr != NULL) {
        next       = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }
    secondHalf = prev;          // head of reversed second half

    // --- step c: interleave ---
    Node* first  = head;
    Node* second = secondHalf;
    while (second != NULL) {
        Node* tmp1 = first->next;
        Node* tmp2 = second->next;

        first->next  = second;
        second->next = tmp1;

        first  = tmp1;
        second = tmp2;
    }
}

/* ============================================================
   freeList  –  free all nodes
   ============================================================ */
void freeList(Node*& head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ============================================================
   MAIN
   ============================================================ */
int main() {
    cout << "========================================\n";
    cout << "   Q2: Singly Linked List Operations\n";
    cout << "========================================\n\n";

    // Build list1: 1 -> 3 -> 5 -> 7 -> 9
    Node* list1 = NULL;
    insertAtEnd(list1, 1);
    insertAtEnd(list1, 3);
    insertAtEnd(list1, 5);
    insertAtEnd(list1, 7);
    insertAtEnd(list1, 9);

    cout << "-- Initial List1 --\n  ";
    display(list1);
    cout << "\n";

    // ---- 2. display ----
    cout << "-- 1. Display --\n  ";
    display(list1);
    cout << "\n";

    // ---- 3. countAndSum ----
    cout << "-- 2. Count and Sum --\n";
    int cnt, sm;
    countAndSum(list1, cnt, sm);
    cout << "  Count = " << cnt << "  |  Sum = " << sm << "\n\n";

    // ---- 4. search ----
    cout << "-- 3. Search --\n";
    search(list1, 5);
    search(list1, 10);
    cout << "\n";

    // ---- 5. deleteNode ----
    cout << "-- 4. Delete Node (value = 5) --\n";
    deleteNode(list1, 5);
    cout << "  After deletion: "; display(list1);
    cout << "\n";

    // ---- 6. isSorted ----
    cout << "-- 5. isSorted --\n";
    cout << "  Is list1 sorted? " << (isSorted(list1) ? "YES" : "NO") << "\n\n";

    // ---- 7. mergeSorted ----
    cout << "-- 6. Merge Two Sorted Lists --\n";
    Node* listA = NULL;
    insertAtEnd(listA, 2);
    insertAtEnd(listA, 4);
    insertAtEnd(listA, 6);

    Node* listB = NULL;
    insertAtEnd(listB, 1);
    insertAtEnd(listB, 3);
    insertAtEnd(listB, 5);
    insertAtEnd(listB, 7);

    cout << "  List A: "; display(listA);
    cout << "  List B: "; display(listB);
    Node* mergedList = mergeSorted(listA, listB);
    cout << "  Merged: "; display(mergedList);
    cout << "\n";

    // ---- 8. concatenate ----
    cout << "-- 7. Concatenate Two Lists --\n";
    Node* c1 = NULL;
    Node* c2 = NULL;
    insertAtEnd(c1, 10);
    insertAtEnd(c1, 20);
    insertAtEnd(c1, 30);
    insertAtEnd(c2, 40);
    insertAtEnd(c2, 50);
    cout << "  List C1: "; display(c1);
    cout << "  List C2: "; display(c2);
    concatenate(c1, c2);
    cout << "  After concat: "; display(c1);
    cout << "\n";

    // ---- 9. reverse ----
    cout << "-- 8. Reverse List --\n";
    cout << "  Before: "; display(c1);
    reverse(c1);
    cout << "  After : "; display(c1);
    cout << "\n";

    // ---- 10. reorder ----
    cout << "-- 9. Reorder {A1,A2..An} -> {A1,An,A2,An-1..} --\n";
    Node* rList = NULL;
    insertAtEnd(rList, 1);
    insertAtEnd(rList, 2);
    insertAtEnd(rList, 3);
    insertAtEnd(rList, 4);
    insertAtEnd(rList, 5);
    cout << "  Before: "; display(rList);
    reorder(rList);
    cout << "  After : "; display(rList);
    cout << "\n";

    // free memory
    freeList(list1);
    freeList(mergedList);
    freeList(c1);
    freeList(rList);

    return 0;
}
