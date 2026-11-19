/*
 * ============================================================
 *  Sandhi151 | DSA Lab | Assignment 3
 *  Q4 : Circular Linked List for Multiplayer Game Players
 * ============================================================
 *  In a circular linked list the LAST node's next pointer
 *  points back to the HEAD (not NULL).
 *
 *  Each node stores one player:
 *    - playerID   (unique integer)
 *    - playerName (name string)
 *
 *  Operations:
 *   a. Display Players    – print all players in the circle
 *   b. Count Players      – count total players
 *   c. Search Player      – find by playerID
 *   d. Remove Player      – delete by playerID (after their turn)
 *
 *  Memory: malloc used for every node.
 * ============================================================
 */

#include <iostream>
#include <cstdlib>      // malloc, free
#include <cstring>      // strcpy
using namespace std;

/* ============================================================
   Player Node
   ============================================================ */
struct PlayerNode {
    int         playerID;
    char        playerName[30];
    PlayerNode* next;
};

/* ============================================================
   createPlayer  –  allocate a new node using malloc
   ============================================================ */
PlayerNode* createPlayer(int id, const char* name) {
    PlayerNode* node = (PlayerNode*) malloc(sizeof(PlayerNode));
    node->playerID = id;
    strcpy(node->playerName, name);
    node->next = NULL;
    return node;
}

/* ============================================================
   addPlayer  –  insert at end, keep circular link
   ============================================================ */
void addPlayer(PlayerNode*& head, int id, const char* name) {
    PlayerNode* newNode = createPlayer(id, name);

    if (head == NULL) {
        head = newNode;
        head->next = head;   // points to itself => circular
        return;
    }

    // Find the last node (next == head)
    PlayerNode* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next    = newNode;
    newNode->next = head;    // maintain circular link
}

/* ============================================================
   a. displayPlayers  –  print all players, show circle
   ============================================================ */
void displayPlayers(PlayerNode* head) {
    if (head == NULL) { cout << "  No players in the game.\n"; return; }

    cout << "  Players in turn order:\n";
    PlayerNode* temp = head;
    int pos = 1;
    do {
        cout << "  [" << pos++ << "] ID: " << temp->playerID
             << "  Name: " << temp->playerName << "\n";
        temp = temp->next;
    } while (temp != head);   // stop when we wrap back to head
    cout << "  (-> circles back to " << head->playerName << ")\n";
}

/* ============================================================
   b. countPlayers  –  count all nodes in the circle
   ============================================================ */
int countPlayers(PlayerNode* head) {
    if (head == NULL) return 0;
    int count = 0;
    PlayerNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

/* ============================================================
   c. searchPlayer  –  search by playerID
   ============================================================ */
PlayerNode* searchPlayer(PlayerNode* head, int id) {
    if (head == NULL) return NULL;
    PlayerNode* temp = head;
    do {
        if (temp->playerID == id) return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

/* ============================================================
   d. removePlayer  –  delete node with matching playerID
   ============================================================ */
void removePlayer(PlayerNode*& head, int id) {
    if (head == NULL) { cout << "  No players to remove.\n"; return; }

    // Find the last node to fix circular link
    PlayerNode* prev = head;
    while (prev->next != head)
        prev = prev->next;

    // Only one player
    if (head->next == head) {
        if (head->playerID == id) {
            cout << "  Removed player: " << head->playerName << "\n";
            free(head);
            head = NULL;
            return;
        }
        cout << "  Player #" << id << " not found.\n";
        return;
    }

    // Head is the target
    if (head->playerID == id) {
        cout << "  Removed player: " << head->playerName << "\n";
        prev->next = head->next;    // last node -> second node
        free(head);
        head = prev->next;          // new head
        return;
    }

    // Search elsewhere
    PlayerNode* curr = head->next;
    PlayerNode* pre  = head;
    do {
        if (curr->playerID == id) {
            cout << "  Removed player: " << curr->playerName << "\n";
            pre->next = curr->next;
            free(curr);
            return;
        }
        pre  = curr;
        curr = curr->next;
    } while (curr != head);

    cout << "  Player #" << id << " not found.\n";
}

/* ============================================================
   freeAllPlayers  –  release every node
   ============================================================ */
void freeAllPlayers(PlayerNode*& head) {
    if (head == NULL) return;

    // Break the circle first
    PlayerNode* last = head;
    while (last->next != head) last = last->next;
    last->next = NULL;  // now it's a normal linear list

    PlayerNode* temp;
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
    cout << "   Q4: Multiplayer Game\n";
    cout << "   (Circular Linked List)\n";
    cout << "========================================\n\n";

    PlayerNode* game = NULL;

    // Add players
    addPlayer(game, 1, "Alice");
    addPlayer(game, 2, "Bob");
    addPlayer(game, 3, "Charlie");
    addPlayer(game, 4, "Diana");
    addPlayer(game, 5, "Eve");

    // ---- a. Display ----
    cout << "-- a. Display All Players --\n";
    displayPlayers(game);
    cout << "\n";

    // ---- b. Count ----
    cout << "-- b. Count Players --\n";
    cout << "  Total players: " << countPlayers(game) << "\n\n";

    // ---- c. Search ----
    cout << "-- c. Search for Player --\n";
    int sid = 3;
    PlayerNode* found = searchPlayer(game, sid);
    if (found)
        cout << "  Found -> ID: " << found->playerID
             << "  Name: " << found->playerName << "\n";
    else
        cout << "  Player #" << sid << " not found.\n";

    sid = 99;
    found = searchPlayer(game, sid);
    if (!found) cout << "  Player #" << sid << " not found.\n";
    cout << "\n";

    // ---- d. Remove (simulate turns) ----
    cout << "-- d. Remove Player After Their Turn --\n";
    cout << "  Bob completes turn -> remove\n";
    removePlayer(game, 2);
    cout << "  Remaining:\n";
    displayPlayers(game);
    cout << "\n";

    cout << "  Diana completes turn -> remove\n";
    removePlayer(game, 4);
    cout << "  Remaining:\n";
    displayPlayers(game);
    cout << "\n";

    cout << "  Player #99 tries to leave (not found):\n";
    removePlayer(game, 99);
    cout << "\n";

    cout << "-- Final Player Count: " << countPlayers(game) << " --\n\n";

    freeAllPlayers(game);
    return 0;
}
