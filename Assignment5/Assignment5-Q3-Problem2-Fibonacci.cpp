/*
 * ============================================================
 *  Assignment 5 | DSA Lab
 *  Q3 - Problem 2: Fibonacci Series
 * ============================================================
 *  RECURRENCE RELATION:
 *    F(n) = F(n-1) + F(n-2)
 *    Base cases: F(0) = 0, F(1) = 1
 *
 *  TIME COMPLEXITY: O(2^n) for naive recursion
 *                   O(n) for optimized (memoization/DP)
 *
 *  EXPLANATION:
 *    Each Fibonacci number is the sum of the two preceding ones.
 *    The sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 *    
 *    F(n) calls F(n-1) and F(n-2), each of which makes 2 calls,
 *    creating an exponential tree of recursive calls.
 * ============================================================
 */

#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// ============================================================
//  METHOD 1: NAIVE RECURSION (Exponential Time)
// ============================================================
/*
 * Algorithm: fibonacci_recursive(n)
 * Input: n (position in Fibonacci sequence)
 * Output: nth Fibonacci number
 * 
 * 1. Base case 1: if n == 0, return 0
 * 2. Base case 2: if n == 1, return 1
 * 3. Recursive case: return fibonacci(n-1) + fibonacci(n-2)
 */

long long fibonacci_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// ============================================================
//  METHOD 2: MEMOIZATION (Top-Down DP) - O(n)
// ============================================================
long long memo[100];

long long fibonacci_memo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Check if already computed
    if (memo[n] != -1) return memo[n];
    
    // Compute and store
    memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
    return memo[n];
}

// ============================================================
//  METHOD 3: ITERATIVE (Bottom-Up DP) - O(n)
// ============================================================
long long fibonacci_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long prev2 = 0;  // F(0)
    long long prev1 = 1;  // F(1)
    long long curr = 0;
    
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return curr;
}

// ============================================================
//  Display recurrence analysis
// ============================================================
void displayAnalysis() {
    cout << "========================================\n";
    cout << "  RECURRENCE RELATION ANALYSIS\n";
    cout << "========================================\n\n";
    
    cout << "Recurrence: F(n) = F(n-1) + F(n-2)\n";
    cout << "Base cases: F(0) = 0, F(1) = 1\n\n";
    
    cout << "Recursion Tree Analysis:\n";
    cout << "                F(5)\n";
    cout << "              /       \\\n";
    cout << "           F(4)       F(3)\n";
    cout << "          /    \\      /   \\\n";
    cout << "       F(3)   F(2) F(2)  F(1)\n";
    cout << "       / \\    / \\   / \\\n";
    cout << "     F(2) F(1)...\n\n";
    
    cout << "Time Complexity Analysis:\n";
    cout << "  - Naive Recursion: O(2^n) - exponential\n";
    cout << "    * Many subproblems computed multiple times\n";
    cout << "    * T(n) ≈ 2*T(n-1) leads to exponential growth\n\n";
    
    cout << "  - With Memoization: O(n) - linear\n";
    cout << "    * Each subproblem computed only once\n";
    cout << "    * n unique subproblems, O(1) per subproblem\n\n";
    
    cout << "  - Iterative (Bottom-up): O(n) - linear\n";
    cout << "    * Single loop from 2 to n\n";
    cout << "    * O(1) space (only stores last 2 values)\n\n";
    
    cout << "Space Complexity:\n";
    cout << "  - Naive: O(n) [recursion stack]\n";
    cout << "  - Memoization: O(n) [memo array + stack]\n";
    cout << "  - Iterative: O(1) [only 3 variables]\n\n";
}

// ============================================================
//  Display Fibonacci sequence
// ============================================================
void displaySequence() {
    cout << "========================================\n";
    cout << "  FIBONACCI SEQUENCE (First 20 terms)\n";
    cout << "========================================\n\n";
    
    cout << "  n  |  F(n)\n";
    cout << "  ---------------\n";
    
    for (int i = 0; i <= 20; i++) {
        cout << "  " << (i < 10 ? " " : "") << i 
             << " |  " << fibonacci_iterative(i) << "\n";
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
    int numTests = 6;
    
    for (int i = 0; i < numTests; i++) {
        int n = testValues[i];
        
        // Initialize memo array
        for (int j = 0; j < 100; j++) memo[j] = -1;
        
        // Measure recursive (skip if n > 35, too slow)
        long long time_rec = 0;
        if (n <= 35) {
            auto start = high_resolution_clock::now();
            fibonacci_recursive(n);
            auto end = high_resolution_clock::now();
            time_rec = duration_cast<microseconds>(end - start).count();
        }
        
        // Measure memoization
        auto start_memo = high_resolution_clock::now();
        fibonacci_memo(n);
        auto end_memo = high_resolution_clock::now();
        long long time_memo = duration_cast<microseconds>(end_memo - start_memo).count();
        
        // Measure iterative
        auto start_iter = high_resolution_clock::now();
        fibonacci_iterative(n);
        auto end_iter = high_resolution_clock::now();
        long long time_iter = duration_cast<microseconds>(end_iter - start_iter).count();
        
        cout << "  " << n << " |  ";
        if (n <= 35)
            cout << time_rec;
        else
            cout << "SKIP (too slow)";
        cout << "     |  " << time_memo 
             << "     |  " << time_iter << "\n";
    }
    
    cout << "\nObservations:\n";
    cout << "• Recursive method grows exponentially\n";
    cout << "• Memoization and iterative are much faster\n";
    cout << "• For n > 40, naive recursion becomes impractical\n\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "========================================\n";
    cout << "  Q3 - Problem 2: Fibonacci Series\n";
    cout << "========================================\n\n";
    
    // Display analysis
    displayAnalysis();
    
    // Display sequence
    displaySequence();
    
    // Performance comparison
    performanceComparison();
    
    // Interactive test
    int n;
    cout << "Enter n to find the nth Fibonacci number: ";
    cin >> n;
    
    if (n < 0 || n > 90) {
        cout << "Please enter n between 0 and 90\n";
        return 1;
    }
    
    // Initialize memo
    for (int j = 0; j < 100; j++) memo[j] = -1;
    
    cout << "\nResults for n = " << n << ":\n";
    cout << "  Fibonacci(" << n << ") = " << fibonacci_iterative(n) << "\n\n";
    
    // Test multiple values
    cout << "========================================\n";
    cout << "  TEST CASES\n";
    cout << "========================================\n\n";
    
    int tests[] = {5, 10, 15, 20, 25, 30};
    for (int i = 0; i < 6; i++) {
        int test_n = tests[i];
        cout << "F(" << test_n << ") = " 
             << fibonacci_iterative(test_n) << "\n";
    }
    
    return 0;
}
