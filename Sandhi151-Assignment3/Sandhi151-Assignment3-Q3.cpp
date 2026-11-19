/*
 * ============================================================
 *  Sandhi151 | DSA Lab | Assignment 3
 *  Q3 : Singly Linked List for Restaurant Orders
 * ============================================================
 *  Each node stores one customer order with:
 *    - orderID   (unique integer)
 *    - itemName  (name of the dish)
 *    - price     (float)
 *
 *  Operations:
 *   a. Display all orders
 *   b. Count orders + calculate total order value
 *   c. Search for an order by orderID
 *   d. Delete an order by orderID
 *
 *  Memory: malloc used for every node.
 * ============================================================
 */

#include <iostream>
#include <cstdlib>      // malloc, free
#include <cstring>      // strcpy, strlen
using namespace std;

/* ============================================================
   Order Node
   ============================================================ */
struct OrderNode {
    int         orderID;
    char        itemName[50];
    float       price;
    OrderNode*  next;
};

/* ============================================================
   createOrder  –  allocate a new order node using malloc
   ============================================================ */
OrderNode* createOrder(int id, const char* item, float price) {
    OrderNode* node = (OrderNode*) malloc(sizeof(OrderNode));
    node->orderID = id;
    strcpy(node->itemName, item);
    node->price = price;
    node->next  = NULL;
    return node;
}

/* ============================================================
   addOrder  –  insert order at the end of the list
   ============================================================ */
void addOrder(OrderNode*& head, int id, const char* item, float price) {
    OrderNode* newNode = createOrder(id, item, price);
    if (head == NULL) { head = newNode; return; }
    OrderNode* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

/* ============================================================
   a. displayOrders  –  print all orders in the list
   ============================================================ */
void displayOrders(OrderNode* head) {
    if (head == NULL) {
        cout << "  No orders currently.\n";
        return;
    }
    cout << "  -------------------------------------------\n";
    cout << "  ID  | Item Name              | Price\n";
    cout << "  -------------------------------------------\n";
    OrderNode* temp = head;
    while (temp != NULL) {
        cout << "  " << temp->orderID
             << "   | " << temp->itemName;
        // padding for alignment
        int pad = 22 - (int)strlen(temp->itemName);
        for (int i = 0; i < pad; i++) cout << " ";
        cout << " | Rs." << temp->price << "\n";
        temp = temp->next;
    }
    cout << "  -------------------------------------------\n";
}

/* ============================================================
   b. countAndTotal  –  count orders and compute total value
   ============================================================ */
void countAndTotal(OrderNode* head, int& count, float& total) {
    count = 0;
    total = 0.0f;
    OrderNode* temp = head;
    while (temp != NULL) {
        count++;
        total += temp->price;
        temp = temp->next;
    }
}

/* ============================================================
   c. searchOrder  –  search by orderID, returns pointer or NULL
   ============================================================ */
OrderNode* searchOrder(OrderNode* head, int id) {
    OrderNode* temp = head;
    while (temp != NULL) {
        if (temp->orderID == id) return temp;
        temp = temp->next;
    }
    return NULL;
}

/* ============================================================
   d. deleteOrder  –  remove node with matching orderID
   ============================================================ */
void deleteOrder(OrderNode*& head, int id) {
    if (head == NULL) { cout << "  No orders to delete.\n"; return; }

    // head is the target
    if (head->orderID == id) {
        OrderNode* temp = head;
        head = head->next;
        free(temp);
        cout << "  Order #" << id << " deleted.\n";
        return;
    }

    OrderNode* prev = head;
    OrderNode* curr = head->next;
    while (curr != NULL) {
        if (curr->orderID == id) {
            prev->next = curr->next;
            free(curr);
            cout << "  Order #" << id << " deleted.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "  Order #" << id << " not found.\n";
}

/* ============================================================
   freeOrders  –  release all nodes
   ============================================================ */
void freeOrders(OrderNode*& head) {
    OrderNode* temp;
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
    cout << "   Q3: Restaurant Order Management\n";
    cout << "   (Singly Linked List)\n";
    cout << "========================================\n\n";

    OrderNode* orders = NULL;

    // Add some orders
    addOrder(orders, 101, "Butter Chicken",  250.0f);
    addOrder(orders, 102, "Paneer Tikka",    180.0f);
    addOrder(orders, 103, "Biryani",         300.0f);
    addOrder(orders, 104, "Gulab Jamun",      80.0f);
    addOrder(orders, 105, "Mango Lassi",      60.0f);

    // ---- a. Display ----
    cout << "-- a. Display All Orders --\n";
    displayOrders(orders);
    cout << "\n";

    // ---- b. Count and Total ----
    cout << "-- b. Count and Total Value --\n";
    int cnt;
    float total;
    countAndTotal(orders, cnt, total);
    cout << "  Total Orders : " << cnt   << "\n";
    cout << "  Total Value  : Rs." << total << "\n\n";

    // ---- c. Search ----
    cout << "-- c. Search for Order --\n";
    int searchID = 103;
    OrderNode* found = searchOrder(orders, searchID);
    if (found)
        cout << "  Found -> ID: " << found->orderID
             << " | Item: " << found->itemName
             << " | Price: Rs." << found->price << "\n";
    else
        cout << "  Order #" << searchID << " not found.\n";

    searchID = 999;
    found = searchOrder(orders, searchID);
    if (!found)
        cout << "  Order #" << searchID << " not found.\n";
    cout << "\n";

    // ---- d. Delete ----
    cout << "-- d. Delete an Order --\n";
    deleteOrder(orders, 102);
    deleteOrder(orders, 999);   // non-existent
    cout << "\n  After deletion:\n";
    displayOrders(orders);
    cout << "\n";

    // Recalculate after deletion
    cout << "-- After Deletion: Count and Total --\n";
    countAndTotal(orders, cnt, total);
    cout << "  Total Orders : " << cnt   << "\n";
    cout << "  Total Value  : Rs." << total << "\n\n";

    freeOrders(orders);
    return 0;
}
