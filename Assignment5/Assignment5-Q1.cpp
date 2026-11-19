/*
 * ============================================================
 *  Assignment 5 | DSA Lab
 *  Q1: Analyze and Compare Time Complexities
 * ============================================================
 *  Implements and measures:
 *   - O(1)         Constant
 *   - O(log n)     Logarithmic
 *   - O(√n)        Square root
 *   - O(n)         Linear
 *   - O(n log n)   Linearithmic
 *   - O(n²)        Quadratic
 *   - O(n³)        Cubic
 *   - O(2^n)       Exponential
 *   - O(n!)        Factorial
 *
 *  Outputs results to CSV and displays analysis
 * ============================================================
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

// ============================================================
//  1. O(1) - Constant Time
// ============================================================
long long complexity_O1(int n) {
    return 1;  // Always 1 operation
}

// ============================================================
//  2. O(log n) - Logarithmic Time
// ============================================================
long long complexity_Ologn(int n) {
    if (n <= 0) return 0;
    long long ops = 0;
    while (n > 1) {
        n /= 2;
        ops++;
    }
    return ops;
}

// ============================================================
//  3. O(√n) - Square Root Time
// ============================================================
long long complexity_Osqrtn(int n) {
    return (long long)sqrt(n);
}

// ============================================================
//  4. O(n) - Linear Time
// ============================================================
long long complexity_On(int n) {
    return n;
}

// ============================================================
//  5. O(n log n) - Linearithmic Time
// ============================================================
long long complexity_Onlogn(int n) {
    if (n <= 0) return 0;
    return (long long)(n * log2(n));
}

// ============================================================
//  6. O(n²) - Quadratic Time
// ============================================================
long long complexity_On2(int n) {
    return (long long)n * n;
}

// ============================================================
//  7. O(n³) - Cubic Time
// ============================================================
long long complexity_On3(int n) {
    return (long long)n * n * n;
}

// ============================================================
//  8. O(2^n) - Exponential Time (limited to small n)
// ============================================================
long long complexity_O2n(int n) {
    if (n > 60) return -1;  // overflow protection
    return (1LL << n);      // 2^n using bit shift
}

// ============================================================
//  9. O(n!) - Factorial Time (limited to small n)
// ============================================================
long long complexity_Onfactorial(int n) {
    if (n > 20) return -1;  // overflow protection
    if (n <= 1) return 1;
    long long fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// ============================================================
//  Generate CSV file with all complexity values
// ============================================================
void generateCSV() {
    ofstream csv("time_complexity_analysis.csv");
    
    csv << "n,O(1),O(log n),O(sqrt n),O(n),O(n log n),O(n^2),O(n^3),O(2^n),O(n!)\n";
    
    // Values to test
    int values[] = {1, 2, 3, 5, 10, 15, 20, 25, 30, 40, 50, 60, 70, 80, 90, 100};
    int numValues = 16;
    
    for (int i = 0; i < numValues; i++) {
        int n = values[i];
        csv << n << ",";
        csv << complexity_O1(n) << ",";
        csv << complexity_Ologn(n) << ",";
        csv << complexity_Osqrtn(n) << ",";
        csv << complexity_On(n) << ",";
        csv << complexity_Onlogn(n) << ",";
        csv << complexity_On2(n) << ",";
        csv << complexity_On3(n) << ",";
        
        long long exp = complexity_O2n(n);
        if (exp == -1) csv << "OVERFLOW,";
        else csv << exp << ",";
        
        long long fact = complexity_Onfactorial(n);
        if (fact == -1) csv << "OVERFLOW";
        else csv << fact;
        
        csv << "\n";
    }
    
    csv.close();
    cout << "✓ CSV file 'time_complexity_analysis.csv' generated successfully!\n\n";
}

// ============================================================
//  Display analysis tables
// ============================================================
void displayTable1() {
    cout << "========================================\n";
    cout << "  TABLE 1: O(1), O(log n), O(√n), O(n), O(n log n)\n";
    cout << "  Range: n = 1 to 100 (selected values)\n";
    cout << "========================================\n";
    cout << setw(6) << "n" 
         << setw(10) << "O(1)"
         << setw(12) << "O(log n)"
         << setw(12) << "O(√n)"
         << setw(10) << "O(n)"
         << setw(14) << "O(n log n)" << "\n";
    cout << "------------------------------------------------------------------------\n";
    
    int values[] = {1, 5, 10, 20, 30, 40, 50, 75, 100};
    for (int i = 0; i < 9; i++) {
        int n = values[i];
        cout << setw(6) << n
             << setw(10) << complexity_O1(n)
             << setw(12) << complexity_Ologn(n)
             << setw(12) << complexity_Osqrtn(n)
             << setw(10) << complexity_On(n)
             << setw(14) << complexity_Onlogn(n) << "\n";
    }
    cout << "\n";
}

void displayTable2() {
    cout << "========================================\n";
    cout << "  TABLE 2: O(n²), O(n³)\n";
    cout << "  Range: n = 1 to 50 (selected values)\n";
    cout << "========================================\n";
    cout << setw(6) << "n" 
         << setw(15) << "O(n²)"
         << setw(18) << "O(n³)" << "\n";
    cout << "----------------------------------------\n";
    
    int values[] = {1, 5, 10, 15, 20, 25, 30, 40, 50};
    for (int i = 0; i < 9; i++) {
        int n = values[i];
        cout << setw(6) << n
             << setw(15) << complexity_On2(n)
             << setw(18) << complexity_On3(n) << "\n";
    }
    cout << "\n";
}

void displayTable3() {
    cout << "========================================\n";
    cout << "  TABLE 3: O(2^n), O(n!)\n";
    cout << "  Range: n = 1, 2, 3, 5, 10, 15, 20\n";
    cout << "========================================\n";
    cout << setw(6) << "n" 
         << setw(20) << "O(2^n)"
         << setw(25) << "O(n!)" << "\n";
    cout << "---------------------------------------------------\n";
    
    int values[] = {1, 2, 3, 5, 10, 15, 20};
    for (int i = 0; i < 7; i++) {
        int n = values[i];
        long long exp = complexity_O2n(n);
        long long fact = complexity_Onfactorial(n);
        
        cout << setw(6) << n << setw(20);
        if (exp == -1) cout << "OVERFLOW";
        else cout << exp;
        
        cout << setw(25);
        if (fact == -1) cout << "OVERFLOW";
        else cout << fact;
        cout << "\n";
    }
    cout << "\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "========================================\n";
    cout << "  Q1: Time Complexity Analysis\n";
    cout << "========================================\n\n";
    
    // Generate CSV file
    generateCSV();
    
    // Display analysis tables
    displayTable1();
    displayTable2();
    displayTable3();
    
    // Analysis summary
    cout << "========================================\n";
    cout << "  COMPLEXITY GROWTH ANALYSIS\n";
    cout << "========================================\n";
    cout << "Slowest Growth (Most Efficient):\n";
    cout << "  1. O(1)         - Constant\n";
    cout << "  2. O(log n)     - Logarithmic\n";
    cout << "  3. O(√n)        - Square root\n";
    cout << "  4. O(n)         - Linear\n";
    cout << "  5. O(n log n)   - Linearithmic\n";
    cout << "  6. O(n²)        - Quadratic\n";
    cout << "  7. O(n³)        - Cubic\n";
    cout << "  8. O(2^n)       - Exponential\n";
    cout << "  9. O(n!)        - Factorial\n";
    cout << "Fastest Growth (Least Efficient)\n\n";
    
    cout << "Key Observations:\n";
    cout << "• O(1) remains constant regardless of input size\n";
    cout << "• O(log n) grows very slowly\n";
    cout << "• O(n²) and O(n³) grow rapidly for large n\n";
    cout << "• O(2^n) and O(n!) become impractical for n > 20\n\n";
    
    cout << "For graphing:\n";
    cout << "• Graph 1: Plot O(1), O(log n), O(√n), O(n), O(n log n) for n=1 to 100\n";
    cout << "• Graph 2: Plot O(n²), O(n³) for n=1 to 50\n";
    cout << "• Graph 3: Show table for O(2^n), O(n!) for small n\n\n";
    
    cout << "Use the CSV file with Excel, Python (matplotlib), or any\n";
    cout << "graphing tool to visualize the complexity curves.\n";
    
    return 0;
}
