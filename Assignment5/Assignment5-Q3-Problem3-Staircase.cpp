/*
 * ============================================================
 *  Assignment 5 | DSA Lab
 *  Q3 - Problem 3: Staircase Problem (Climbing Stairs)
 * ============================================================
 *  PROBLEM:
 *    You can climb a staircase of n steps by taking either
 *    1 step or 2 steps at a time. Find the number of distinct
 *    ways to reach the top.
 *
 *  RECURRENCE RELATION:
 *    S(n) = S(n-1) + S(n-2)
 *    Base cases: S(1) = 1, S(2) = 2
 *
 *  TIME COMPLEXITY: O(2^n) for naive recursion
 *                   O(n) for optimized
 *
 *  EXPLANATION:
 *    To reach step n, you can come from:
 *    - Step (n-1) by taking 1 step  → S(n-1) ways
 *    - Step (n-2) by taking 2 steps → S(n-2) ways
 *    
 *    Total ways: S(n) = S(n-1) + S(n-2)
 *    
 *    This is similar to Fibonacci, but with different base cases!
 * ============================================================
 */

#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// ============================================================
//  METHOD 1: NAIVE RECURSION
// ============================================================
/*
 * Algorithm: climbStairs_recursive(n)
 * Input: n (number of steps)
 * Output: number of ways to climb n steps
 * 
 * 1. Base case 1: if n == 1, return 1 (one way: 1 step)
 * 2. Base case 2: if n == 2, return 2 (two ways: 1+1 or 2)
 * 3. Recursive case: return climbStairs(n-1) + climbStairs(n-2)
 */

long long climbStairs_recursive(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs_recursive(n - 1) + climbStairs_recursive(n - 2);
}

// ============================================================
//  METHOD 2: MEMOIZATION (Top-Down DP)
// ============================================================
long long memo[100];

long long climbStairs_memo(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    if (memo[n] != -1) return memo[n];
    
    memo[n] = climbStairs_memo(n - 1) + climbStairs_memo(n - 2);
    return memo[n];
}

// ============================================================
//  METHOD 3: ITERATIVE (Bottom-Up DP)
// ============================================================
long long climbStairs_iterative(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    long long prev2 = 1;  // S(1)
    long long prev1 = 2;  // S(2)
    long long curr = 0;
    
    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return curr;
}

// ============================================================
//  Display detailed ways for small n
// ============================================================
void displayWays(int n) {
    if (n == 1) {
        cout << "  Ways: {1}\n";
    } else if (n == 2) {
        cout << "  Ways: {1+1, 2}\n";
    } else if (n == 3) {
        cout << "  Ways: {1+1+1, 1+2, 2+1}\n";
    } else if (n == 4) {
        cout << "  Ways: {1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2}\n";
    } else if (n == 5) {
        cout << "  Ways: {1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1,\n";
        cout << "         1+2+2, 2+1+2, 2+2+1}\n";
    }
}

// ============================================================
//  Display recurrence analysis
// ============================================================
void displayAnalysis() {
    cout << "========================================\n";
    cout << "  RECURRENCE RELATION ANALYSIS\n";
    cout << "========================================\n\n";
    
    cout << "Problem: Climb n stairs, taking 1 or 2 steps at a time\n";
    cout << "Question: How many distinct ways to reach the top?\n\n";
    
    cout << "Recurrence: S(n) = S(n-1) + S(n-2)\n";
    cout << "Base cases: S(1) = 1, S(2) = 2\n\n";
    
    cout << "Explanation:\n";
    cout << "  To reach step n, you can:\n";
    cout << "  1. Take 1 step from (n-1) → S(n-1) ways\n";
    cout << "  2. Take 2 steps from (n-2) → S(n-2) ways\n";
    cout << "  Total: S(n) = S(n-1) + S(n-2)\n\n";
    
    cout << "Pattern Recognition:\n";
    cout << "  S(1) = 1\n";
    cout << "  S(2) = 2\n";
    cout << "  S(3) = S(2) + S(1) = 2 + 1 = 3\n";
    cout << "  S(4) = S(3) + S(2) = 3 + 2 = 5\n";
    cout << "  S(5) = S(4) + S(3) = 5 + 3 = 8\n";
    cout << "  This is Fibonacci-like with S(1)=1, S(2)=2!\n\n";
    
    cout << "Time Complexity:\n";
    cout << "  - Naive Recursion: O(2^n)\n";
    cout << "  - With Memoization: O(n)\n";
    cout << "  - Iterative: O(n)\n";
    cout << "Space Complexity:\n";
    cout << "  - Naive: O(n) [stack]\n";
    cout << "  - Memoization: O(n)\n";
    cout << "  - Iterative: O(1)\n\n";
}

// ============================================================
//  Display ways for small values
// ============================================================
void displaySmallCases() {
    cout << "========================================\n";
    cout << "  WAYS TO CLIMB (Small Cases)\n";
    cout << "========================================\n\n";
    
    for (int n = 1; n <= 5; n++) {
        cout << "n = " << n << ": " << climbStairs_iterative(n) 
             << " ways\n";
        displayWays(n);
        cout << "\n";
    }
}

// ============================================================
//  Display sequence
// ============================================================
void displaySequence() {
    cout << "========================================\n";
    cout << "  NUMBER OF WAYS FOR DIFFERENT n\n";
    cout << "========================================\n\n";
    
    cout << "   n  |  Ways\n";
    cout << "  --------------\n";
    
    for (int i = 1; i <= 20; i++) {
        cout << "  " << (i < 10 ? " " : "") << i 
             << "  |  " << climbStairs_iterative(i) << "\n";
    }
    cout << "\n";
}

// ============================================================
//  Performance comparison
// ============================================================
void performanceComparison() {
    cout << "========================================\n";
    cout << "  PERFORMANCE COMPARISON\n";
    cout << "========================================\n\n";
    
    cout << "  n  | Recursive(µs) | Memo(µs) | Iterative(µs)\n";
    cout << "  -------------------------------------------------\n";
    
    int testValues[] = {10, 15, 20, 25, 30, 35};
    
    for (int i = 0; i < 6; i++) {
        int n = testValues[i];
        
        // Initialize memo
        for (int j = 0; j < 100; j++) memo[j] = -1;
        
        // Measure recursive (skip if too large)
        long long time_rec = 0;
        if (n <= 35) {
            auto start = high_resolution_clock::now();
            climbStairs_recursive(n);
            auto end = high_resolution_clock::now();
            time_rec = duration_cast<microseconds>(end - start).count();
        }
        
        // Measure memoization
        auto start_memo = high_resolution_clock::now();
        climbStairs_memo(n);
        auto end_memo = high_resolution_clock::now();
        long long time_memo = duration_cast<microseconds>(end_memo - start_memo).count();
        
        // Measure iterative
        auto start_iter = high_resolution_clock::now();
        climbStairs_iterative(n);
        auto end_iter = high_resolution_clock::now();
        long long time_iter = duration_cast<microseconds>(end_iter - start_iter).count();
        
        cout << "  " << n << " |  ";
        if (n <= 35)
            cout << time_rec;
        else
            cout << "SKIP";
        cout << "     |  " << time_memo 
             << "     |  " << time_iter << "\n";
    }
    cout << "\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "========================================\n";
    cout << "  Q3 - Problem 3: Staircase Problem\n";
    cout << "========================================\n\n";
    
    // Display analysis
    displayAnalysis();
    
    // Display small cases with actual ways
    displaySmallCases();
    
    // Display sequence
    displaySequence();
    
    // Performance comparison
    performanceComparison();
    
    // Interactive test
    int n;
    cout << "Enter number of stairs to climb: ";
    cin >> n;
    
    if (n <= 0 || n > 90) {
        cout << "Please enter n between 1 and 90\n";
        return 1;
    }
    
    cout << "\nNumber of ways to climb " << n << " stairs: " 
         << climbStairs_iterative(n) << "\n\n";
    
    // Test multiple values
    cout << "========================================\n";
    cout << "  TEST CASES\n";
    cout << "========================================\n\n";
    
    int tests[] = {5, 10, 15, 20, 25, 30};
    for (int i = 0; i < 6; i++) {
        int test_n = tests[i];
        cout << "S(" << test_n << ") = " 
             << climbStairs_iterative(test_n) << " ways\n";
    }
    
    return 0;
}
