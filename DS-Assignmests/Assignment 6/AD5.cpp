// #include <iostream>
// #include <vector>
// using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;
//     Node* prev;
//     Node* up;
//     Node* down;

//     Node(int v) : val(v), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
// };

// class GridDLL {
// public:
//     GridDLL(const vector<vector<int>>& mat) {
//         if (mat.empty() || mat[0].empty()) {
//             rows = cols = 0;
//             head = nullptr;
//             return;
//         }

//         rows = static_cast<int>(mat.size());
//         cols = static_cast<int>(mat[0].size());

//         nodes.assign(rows, vector<Node*>(cols, nullptr));

//         for (int i = 0; i < rows; ++i)
//             for (int j = 0; j < cols; ++j)
//                 nodes[i][j] = new Node(mat[i][j]);

//         for (int i = 0; i < rows; ++i)
//             for (int j = 0; j < cols; ++j) {
//                 if (j + 1 < cols) {
//                     nodes[i][j]->next = nodes[i][j+1];
//                     nodes[i][j+1]->prev = nodes[i][j];
//                 }
//                 if (i + 1 < rows) {
//                     nodes[i][j]->down = nodes[i+1][j];
//                     nodes[i+1][j]->up = nodes[i][j];
//                 }
//             }

//         head = nodes[0][0];
//     }

//     ~GridDLL() {
//         for (int i = 0; i < rows; ++i)
//             for (int j = 0; j < cols; ++j)
//                 delete nodes[i][j];
//     }

//     Node* getHead() const { return head; }

//     void printRowMajor() const {
//         for (int i = 0; i < rows; ++i) {
//             Node* cur = nodes[i][0];
//             for (int j = 0; j < cols; ++j) {
//                 cout << cur->val << (j + 1 < cols ? ' ' : '\n');
//                 cur = cur->next;
//             }
//         }
//     }

//     void printColumnMajor() const {
//         for (int j = 0; j < cols; ++j) {
//             Node* cur = nodes[0][j];
//             for (int i = 0; i < rows; ++i) {
//                 cout << cur->val << (i + 1 < rows ? ' ' : '\n');
//                 cur = cur->down;
//             }
//         }
//     }

// private:
//     int rows = 0, cols = 0;
//     vector<vector<Node*>> nodes;
//     Node* head = nullptr;
// };

// int main() {
//     vector<vector<int>> mat = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     GridDLL grid(mat);

//     Node* head = grid.getHead();
//     if (head) {
//         cout << "Head value: " << head->val << "\n";
//         cout << "Row-major traversal:\n";
//         grid.printRowMajor();
//         cout << "Column-major traversal:\n";
//         grid.printColumnMajor();
//     } else {
//         cout << "Empty grid.\n";
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

class GridDLL{
    int data;
    GridDLL* next;
    GridDLL* prev;
    GridDLL* up;
    GridDLL* down;

    public:
    GridDLL(){}
    GridDLL(int val): data(val), next(nullptr), prev(nullptr), up(nullptr), down(nullptr){}

    void makeGrid(vector<vector<int>> grid){
        int a = grid.size();
        int b = grid[0].size();
        GridDLL** GRID = new GridDLL*[a]; // Dynamically allocate array of pointers
        for (int i = 0; i < a; ++i) {
            GRID[i] = new GridDLL[b]; // Dynamically allocate each row as an array of objects
        }
        for(int i=0;i<a;i++){
            for(int j=1;j<b;j++) {
                GRID[i][j-1].next = GRID[i][j];
            }

        }
        
    }
};

int main() {
    return 0;
}