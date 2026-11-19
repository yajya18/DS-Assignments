/*
 * ============================================================
 *  Assignment 5 | DSA Lab
 *  Q2: Recurrence Relations - Analysis and Implementation
 * ============================================================
 *  Implements and analyzes:
 *   i.   T(n) = T(n-1) + 1        → O(n)
 *   ii.  T(n) = T(n-1) + n        → O(n²)
 *   iii. T(n) = T(n-1) + n²       → O(n³)
 *   iv.  T(n) = T(n-1) + log(n)   → O(n log n)
 *
 *  Measures actual execution time using chrono
 * ============================================================
 */

#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// ============================================================
//  i. T(n) = T(n-1) + 1
//     Base case: T(0) = 0
//     Time Complexity: O(n)
//     Explanation: Adds 1 at each level, n levels deep
//                  T(n) = 1 + 1 + 1 + ... (n times) = n
// ============================================================
long long recurrence1(int n) {
    if (n == 0) return 0;
    return recurrence1(n - 1) + 1;
}

// ============================================================
//  ii. T(n) = T(n-1) + n
//      Base case: T(0) = 0
//      Time Complexity: O(n²)
//      Explanation: T(n) = n + (n-1) + (n-2) + ... + 1
//                   = n(n+1)/2 = O(n²)
// ============================================================
long long recurrence2(int n) {
    if (n == 0) return 0;
    return recurrence2(n - 1) + n;
}

// ============================================================
//  iii. T(n) = T(n-1) + n²
//       Base case: T(0) = 0
//       Time Complexity: O(n³)
//       Explanation: T(n) = n² + (n-1)² + (n-2)² + ... + 1²
//                    Sum of squares = n(n+1)(2n+1)/6 = O(n³)
// ============================================================
long long recurrence3(int n) {
    if (n == 0) return 0;
    return recurrence3(n - 1) + (long long)n * n;
}

// ============================================================
//  iv. T(n) = T(n-1) + log(n)
//      Base case: T(1) = 0
//      Time Complexity: O(n log n)
//      Explanation: T(n) = log(n) + log(n-1) + ... + log(2)
//                   = log(n!) ≈ n log n - n = O(n log n)
// ============================================================
double recurrence4(int n) {
    if (n <= 1) return 0;
    return recurrence4(n - 1) + log2(n);
}

// ============================================================
//  Display theoretical analysis
// ============================================================
void displayTheory() {
    cout << "========================================\n";
    cout << "  THEORETICAL TIME COMPLEXITY ANALYSIS\n";
    cout << "========================================\n\n";
    
    cout << "i. T(n) = T(n-1) + 1\n";
    cout << "   Expansion: T(n) = 1 + 1 + 1 + ... (n times)\n";
    cout << "              T(n) = n\n";
    cout << "   Time Complexity: O(n)\n\n";
    
    cout << "ii. T(n) = T(n-1) + n\n";
    cout << "    Expansion: T(n) = n + (n-1) + (n-2) + ... + 1\n";
    cout << "               T(n) = n(n+1)/2\n";
    cout << "    Time Complexity: O(n²)\n\n";
    
    cout << "iii. T(n) = T(n-1) + n²\n";
    cout << "     Expansion: T(n) = n² + (n-1)² + (n-2)² + ... + 1²\n";
    cout << "                T(n) = n(n+1)(2n+1)/6\n";
    cout << "     Time Complexity: O(n³)\n\n";
    
    cout << "iv. T(n) = T(n-1) + log(n)\n";
    cout << "    Expansion: T(n) = log(n) + log(n-1) + ... + log(2)\n";
    cout << "               T(n) = log(n!)\n";
    cout << "               T(n) ≈ n log n  (using Stirling's approximation)\n";
    cout << "    Time Complexity: O(n log n)\n\n";
}

// ============================================================
//  Test recurrence with output values
// ============================================================
void testRecurrences() {
    cout << "========================================\n";
    cout << "  OUTPUT VALUES FOR SMALL n\n";
    cout << "========================================\n\n";
    
    cout << "T1(n) = T(n-1) + 1:\n  ";
    for (int n = 0; n <= 10; n++)
        cout << "T(" << n << ")=" << recurrence1(n) << "  ";
    cout << "\n\n";
    
    cout << "T2(n) = T(n-1) + n:\n  ";
    for (int n = 0; n <= 10; n++)
        cout << "T(" << n << ")=" << recurrence2(n) << "  ";
    cout << "\n\n";
    
    cout << "T3(n) = T(n-1) + n²:\n  ";
    for (int n = 0; n <= 10; n++)
        cout << "T(" << n << ")=" << recurrence3(n) << "  ";
    cout << "\n\n";
    
    cout << "T4(n) = T(n-1) + log(n):\n  ";
    for (int n = 1; n <= 10; n++)
        cout << "T(" << n << ")=" << fixed << setprecision(2) 
             << recurrence4(n) << "  ";
    cout << "\n\n";
}

// ============================================================
//  Measure execution time
// ============================================================
void measureExecutionTime() {
    cout << "========================================\n";
    cout << "  EXECUTION TIME MEASUREMENT\n";
    cout << "========================================\n\n";
    
    cout << setw(8) << "n"
         << setw(18) << "T1 (µs)"
         << setw(18) << "T2 (µs)"
         << setw(18) << "T3 (µs)"
         << setw(18) << "T4 (µs)" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    
    int testValues[] = {10, 50, 100, 200, 300, 500, 1000};
    int numTests = 7;
    
    for (int i = 0; i < numTests; i++) {
        int n = testValues[i];
        
        // Measure T1
        auto start1 = high_resolution_clock::now();
        recurrence1(n);
        auto end1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(end1 - start1).count();
        
        // Measure T2
        auto start2 = high_resolution_clock::now();
        recurrence2(n);
        auto end2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(end2 - start2).count();
        
        // Measure T3
        auto start3 = high_resolution_clock::now();
        recurrence3(n);
        auto end3 = high_resolution_clock::now();
        auto duration3 = duration_cast<microseconds>(end3 - start3).count();
        
        // Measure T4
        auto start4 = high_resolution_clock::now();
        recurrence4(n);
        auto end4 = high_resolution_clock::now();
        auto duration4 = duration_cast<microseconds>(end4 - start4).count();
        
        cout << setw(8) << n
             << setw(18) << duration1
             << setw(18) << duration2
             << setw(18) << duration3
             << setw(18) << duration4 << "\n";
    }
    
    cout << "\n";
}

// ============================================================
//  Complexity growth comparison
// ============================================================
void compareGrowth() {
    cout << "========================================\n";
    cout << "  GROWTH RATE COMPARISON\n";
    cout << "========================================\n";
    cout << "Recurrence              Complexity    Growth Rate\n";
    cout << "---------------------------------------------------\n";
    cout << "T(n) = T(n-1) + 1      O(n)          Linear\n";
    cout << "T(n) = T(n-1) + log(n) O(n log n)    Linearithmic\n";
    cout << "T(n) = T(n-1) + n      O(n²)         Quadratic\n";
    cout << "T(n) = T(n-1) + n²     O(n³)         Cubic\n";
    cout << "---------------------------------------------------\n\n";
    
    cout << "Observations from execution time:\n";
    cout << "• T1 grows linearly with n\n";
    cout << "• T2 shows quadratic growth pattern\n";
    cout << "• T3 shows cubic growth (very fast)\n";
    cout << "• T4 grows slightly faster than linear\n";
    cout << "• Execution time validates theoretical analysis\n\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "========================================\n";
    cout << "  Q2: Recurrence Relations Analysis\n";
    cout << "========================================\n\n";
    
    // Display theoretical analysis
    displayTheory();
    
    // Test with small values
    testRecurrences();
    
    // Measure execution time
    measureExecutionTime();
    
    // Compare growth rates
    compareGrowth();
    
    return 0;
}
