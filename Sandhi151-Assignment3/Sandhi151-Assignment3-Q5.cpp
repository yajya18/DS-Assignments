/*
 * ============================================================
 *  Sandhi151 | DSA Lab | Assignment 3
 *  Q5 : Doubly Linked List for Managing Students in a Class
 * ============================================================
 *  A doubly linked list has BOTH a next AND a prev pointer
 *  in every node, so we can traverse FORWARD and BACKWARD.
 *
 *  Each node stores one student:
 *    - studentID   (unique integer)
 *    - studentName (name string)
 *    - grade       (char e.g. 'A', 'B')
 *
 *  Operations:
 *   a. Display Students (forward + backward)
 *   b. Count Students
 *   c. Search by studentID or name
 *   d. Delete a student (works from any end due to prev ptr)
 *
 *  Memory: malloc used for every node.
 * ============================================================
 */

#include <iostream>
#include <cstdlib>      // malloc, free
#include <cstring>      // strcpy, strcmp
using namespace std;

/* ============================================================
   Student Node  –  doubly linked
   ============================================================ */
struct StudentNode {
    int          studentID;
    char         studentName[40];
    char         grade;
    StudentNode* next;
    StudentNode* prev;
};

/* ============================================================
   createStudent  –  allocate with malloc
   ============================================================ */
StudentNode* createStudent(int id, const char* name, char grade) {
    StudentNode* node = (StudentNode*) malloc(sizeof(StudentNode));
    node->studentID = id;
    strcpy(node->studentName, name);
    node->grade = grade;
    node->next  = NULL;
    node->prev  = NULL;
    return node;
}

/* ============================================================
   insertAtEnd  –  add to the tail, link prev pointer too
   ============================================================ */
void insertAtEnd(StudentNode*& head, StudentNode*& tail,
                 int id, const char* name, char grade) {
    StudentNode* newNode = createStudent(id, name, grade);

    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next    = newNode;
    tail          = newNode;
}

/* ============================================================
   a. displayForward  –  head to tail
   ============================================================ */
void displayForward(StudentNode* head) {
    if (head == NULL) { cout << "  List is empty.\n"; return; }
    cout << "  Forward : ";
    StudentNode* temp = head;
    while (temp != NULL) {
        cout << "[" << temp->studentID << "] " << temp->studentName
             << " (" << temp->grade << ")";
        if (temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

/* ============================================================
   a. displayBackward  –  tail to head
   ============================================================ */
void displayBackward(StudentNode* tail) {
    if (tail == NULL) { cout << "  List is empty.\n"; return; }
    cout << "  Backward: ";
    StudentNode* temp = tail;
    while (temp != NULL) {
        cout << "[" << temp->studentID << "] " << temp->studentName
             << " (" << temp->grade << ")";
        if (temp->prev != NULL) cout << " <-> ";
        temp = temp->prev;
    }
    cout << " -> NULL\n";
}

/* ============================================================
   b. countStudents
   ============================================================ */
int countStudents(StudentNode* head) {
    int count = 0;
    StudentNode* temp = head;
    while (temp != NULL) { count++; temp = temp->next; }
    return count;
}

/* ============================================================
   c. searchByID  –  linear search forward
   ============================================================ */
StudentNode* searchByID(StudentNode* head, int id) {
    StudentNode* temp = head;
    while (temp != NULL) {
        if (temp->studentID == id) return temp;
        temp = temp->next;
    }
    return NULL;
}

/* ============================================================
   c. searchByName  –  linear search forward (case-sensitive)
   ============================================================ */
StudentNode* searchByName(StudentNode* head, const char* name) {
    StudentNode* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->studentName, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

/* ============================================================
   d. deleteStudent  –  delete by studentID.
   Because we have prev pointers, no need to start from head.
   We can unlink the node directly once found.
   ============================================================ */
void deleteStudent(StudentNode*& head, StudentNode*& tail, int id) {
    if (head == NULL) { cout << "  List is empty.\n"; return; }

    // Search for the node
    StudentNode* curr = head;
    while (curr != NULL && curr->studentID != id)
        curr = curr->next;

    if (curr == NULL) {
        cout << "  Student #" << id << " not found.\n";
        return;
    }

    cout << "  Deleted: " << curr->studentName << " (ID " << id << ")\n";

    // Fix prev node's next pointer
    if (curr->prev != NULL)
        curr->prev->next = curr->next;
    else
        head = curr->next;   // deleted head

    // Fix next node's prev pointer
    if (curr->next != NULL)
        curr->next->prev = curr->prev;
    else
        tail = curr->prev;   // deleted tail

    free(curr);
}

/* ============================================================
   freeAll  –  release every node
   ============================================================ */
void freeAll(StudentNode*& head, StudentNode*& tail) {
    StudentNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}

/* ============================================================
   MAIN
   ============================================================ */
int main() {
    cout << "========================================\n";
    cout << "   Q5: Student Class Management\n";
    cout << "   (Doubly Linked List)\n";
    cout << "========================================\n\n";

    StudentNode* head = NULL;
    StudentNode* tail = NULL;

    // Add students
    insertAtEnd(head, tail, 1001, "Aarav Sharma",   'A');
    insertAtEnd(head, tail, 1002, "Priya Mehta",    'B');
    insertAtEnd(head, tail, 1003, "Rohan Gupta",    'A');
    insertAtEnd(head, tail, 1004, "Sneha Patel",    'C');
    insertAtEnd(head, tail, 1005, "Vikram Singh",   'B');

    // ---- a. Display ----
    cout << "-- a. Display Students --\n";
    displayForward(head);
    displayBackward(tail);
    cout << "\n";

    // ---- b. Count ----
    cout << "-- b. Count Students --\n";
    cout << "  Total students: " << countStudents(head) << "\n\n";

    // ---- c. Search by ID ----
    cout << "-- c. Search by Student ID --\n";
    int sid = 1003;
    StudentNode* found = searchByID(head, sid);
    if (found)
        cout << "  Found -> ID: " << found->studentID
             << "  Name: " << found->studentName
             << "  Grade: " << found->grade << "\n";
    else
        cout << "  Student #" << sid << " not found.\n";

    // ---- c. Search by Name ----
    cout << "-- c. Search by Name --\n";
    const char* sname = "Priya Mehta";
    found = searchByName(head, sname);
    if (found)
        cout << "  Found -> ID: " << found->studentID
             << "  Name: " << found->studentName
             << "  Grade: " << found->grade << "\n";
    else
        cout << "  \"" << sname << "\" not found.\n";

    const char* unknown = "John Doe";
    found = searchByName(head, unknown);
    if (!found)
        cout << "  \"" << unknown << "\" not found.\n";
    cout << "\n";

    // ---- d. Delete ----
    cout << "-- d. Delete a Student --\n";
    deleteStudent(head, tail, 1002);   // middle node
    deleteStudent(head, tail, 1001);   // head node
    deleteStudent(head, tail, 9999);   // non-existent
    cout << "\n  After deletions:\n";
    displayForward(head);
    displayBackward(tail);
    cout << "\n";

    cout << "-- Remaining Students: " << countStudents(head) << " --\n\n";

    freeAll(head, tail);
    return 0;
}
