/*
 * ============================================================
 *  Assignment 5 | DSA Lab
 *  Q3 - Problem 1: Tower of Hanoi
 * ============================================================
 *  RECURRENCE RELATION:
 *    T(n) = 2*T(n-1) + 1
 *    Base case: T(1) = 1
 *
 *  TIME COMPLEXITY: O(2^n)
 *
 *  EXPLANATION:
 *    To move n disks from source to destination:
 *    1. Move (n-1) disks from source to auxiliary    → T(n-1)
 *    2. Move largest disk from source to destination → 1
 *    3. Move (n-1) disks from auxiliary to destination → T(n-1)
 *    
 *    Therefore: T(n) = T(n-1) + 1 + T(n-1) = 2*T(n-1) + 1
 *
 *  SOLUTION:
 *    Expanding: T(n) = 2^n - 1 moves
 * ============================================================
 */

#include <iostream>
#include <cmath>
using namespace std;

// Global counter for number of moves
int moveCount = 0;

// ============================================================
//  RECURSIVE ALGORITHM
// ============================================================
/*
 * Algorithm: towerOfHanoi(n, source, destination, auxiliary)
 * Input: n (number of disks), source pole, destination pole, auxiliary pole
 * Output: Prints all moves
 * 
 * 1. Base case: if n == 1
 *       Move disk 1 from source to destination
 *       Return
 * 2. Recursive case:
 *    a. Move (n-1) disks from source to auxiliary using destination
 *    b. Move largest disk (n) from source to destination
 *    c. Move (n-1) disks from auxiliary to destination using source
 */

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: only one disk
    if (n == 1) {
        moveCount++;
        cout << "  Move disk 1 from " << source 
             << " to " << destination << "\n";
        return;
    }
    
    // Step 1: Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Step 2: Move the largest disk from source to destination
    moveCount++;
    cout << "  Move disk " << n << " from " << source 
         << " to " << destination << "\n";
    
    // Step 3: Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// ============================================================
//  Calculate total moves (without printing)
// ============================================================
int countMoves(int n) {
    if (n == 1) return 1;
    return 2 * countMoves(n - 1) + 1;
}

// ============================================================
//  Display recurrence analysis
// ============================================================
void displayAnalysis() {
    cout << "========================================\n";
    cout << "  RECURRENCE RELATION ANALYSIS\n";
    cout << "========================================\n\n";
    
    cout << "Recurrence: T(n) = 2*T(n-1) + 1\n";
    cout << "Base case:  T(1) = 1\n\n";
    
    cout << "Expansion:\n";
    cout << "  T(n) = 2*T(n-1) + 1\n";
    cout << "       = 2*(2*T(n-2) + 1) + 1 = 2²*T(n-2) + 2 + 1\n";
    cout << "       = 2²*(2*T(n-3) + 1) + 2 + 1 = 2³*T(n-3) + 4 + 2 + 1\n";
    cout << "       = ...\n";
    cout << "       = 2^(n-1)*T(1) + 2^(n-2) + ... + 2 + 1\n";
    cout << "       = 2^(n-1) + 2^(n-2) + ... + 2 + 1\n";
    cout << "       = 2^n - 1\n\n";
    
    cout << "Time Complexity: O(2^n)\n";
    cout << "Space Complexity: O(n) [recursion stack depth]\n\n";
}

// ============================================================
//  Test with different values
// ============================================================
void testDifferentValues() {
    cout << "========================================\n";
    cout << "  MOVE COUNT FOR DIFFERENT n\n";
    cout << "========================================\n\n";
    
    cout << "   n  |  Moves (2^n - 1)\n";
    cout << "  -----------------------\n";
    
    for (int n = 1; n <= 10; n++) {
        int moves = countMoves(n);
        cout << "   " << n << "  |  " << moves << "\n";
    }
    cout << "\n";
    
    cout << "For larger n:\n";
    cout << "  n=15: " << ((1 << 15) - 1) << " moves\n";
    cout << "  n=20: " << ((1 << 20) - 1) << " moves\n";
    cout << "  n=30: " << ((1LL << 30) - 1) << " moves\n\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "========================================\n";
    cout << "  Q3 - Problem 1: Tower of Hanoi\n";
    cout << "========================================\n\n";
    
    // Display analysis
    displayAnalysis();
    
    // Test with different values
    testDifferentValues();
    
    // Interactive test
    int n;
    cout << "Enter number of disks (1-10 recommended): ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid input!\n";
        return 1;
    }
    
    cout << "\nSolving Tower of Hanoi for " << n << " disks:\n";
    cout << "Poles: A (source), B (auxiliary), C (destination)\n\n";
    
    moveCount = 0;
    towerOfHanoi(n, 'A', 'C', 'B');
    
    cout << "\n✓ Total moves: " << moveCount << "\n";
    cout << "  Expected (2^n - 1): " << (int)(pow(2, n) - 1) << "\n\n";
    
    // Additional test cases
    cout << "========================================\n";
    cout << "  ADDITIONAL TEST CASES\n";
    cout << "========================================\n\n";
    
    for (int test = 3; test <= 5; test++) {
        cout << "Test with n = " << test << ":\n";
        moveCount = 0;
        towerOfHanoi(test, 'A', 'C', 'B');
        cout << "Total moves: " << moveCount << "\n\n";
    }
    
    return 0;
}
