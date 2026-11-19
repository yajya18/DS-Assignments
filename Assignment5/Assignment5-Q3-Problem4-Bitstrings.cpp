/*
 * ============================================================
 *  Assignment 5 | DSA Lab
 *  Q3 - Problem 4: Bitstrings Without Consecutive Zeros
 * ============================================================
 *  PROBLEM:
 *    Generate bitstrings of length n that do NOT contain
 *    consecutive zeros (no "00" substring).
 *
 *  RECURRENCE RELATION:
 *    B(n) = B(n-1) + B(n-2)
 *    Base cases: B(1) = 2, B(2) = 3
 *
 *  TIME COMPLEXITY: O(2^n) for naive recursion
 *                   O(n) for optimized
 *
 *  EXPLANATION:
 *    For a bitstring of length n:
 *    Case 1: If last bit is '1', previous (n-1) bits can be
 *            any valid bitstring → B(n-1) ways
 *    Case 2: If last bit is '0', previous bit MUST be '1',
 *            and the first (n-2) bits can be any valid 
 *            bitstring → B(n-2) ways
 *    
 *    Total: B(n) = B(n-1) + B(n-2)
 *    
 *    This is Fibonacci-like with B(1)=2, B(2)=3!
 * ============================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// ============================================================
//  Count valid bitstrings (no consecutive zeros)
// ============================================================
/*
 * Algorithm: countBitstrings(n)
 * Input: n (length of bitstring)
 * Output: number of valid bitstrings
 * 
 * 1. Base case 1: if n == 1, return 2 (strings: "0", "1")
 * 2. Base case 2: if n == 2, return 3 (strings: "01", "10", "11")
 * 3. Recursive case: return countBitstrings(n-1) + countBitstrings(n-2)
 */

long long countBitstrings_recursive(int n) {
    if (n == 1) return 2;  // "0", "1"
    if (n == 2) return 3;  // "01", "10", "11"
    return countBitstrings_recursive(n - 1) + countBitstrings_recursive(n - 2);
}

// ============================================================
//  Iterative version (efficient)
// ============================================================
long long countBitstrings_iterative(int n) {
    if (n == 1) return 2;
    if (n == 2) return 3;
    
    long long prev2 = 2;  // B(1)
    long long prev1 = 3;  // B(2)
    long long curr = 0;
    
    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return curr;
}

// ============================================================
//  Generate all valid bitstrings (for small n)
// ============================================================
void generateBitstrings(int n, string current, vector<string>& result) {
    if (current.length() == n) {
        result.push_back(current);
        return;
    }
    
    // Always can add '1'
    generateBitstrings(n, current + "1", result);
    
    // Can add '0' only if last char is not '0'
    if (current.empty() || current.back() != '0') {
        generateBitstrings(n, current + "0", result);
    }
}

vector<string> getAllBitstrings(int n) {
    vector<string> result;
    generateBitstrings(n, "", result);
    return result;
}

// ============================================================
//  Check if a bitstring is valid
// ============================================================
bool isValidBitstring(const string& s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '0')
            return false;
    }
    return true;
}

// ============================================================
//  Display recurrence analysis
// ============================================================
void displayAnalysis() {
    cout << "========================================\n";
    cout << "  RECURRENCE RELATION ANALYSIS\n";
    cout << "========================================\n\n";
    
    cout << "Problem: Count bitstrings of length n with no consecutive zeros\n\n";
    
    cout << "Recurrence: B(n) = B(n-1) + B(n-2)\n";
    cout << "Base cases: B(1) = 2, B(2) = 3\n\n";
    
    cout << "Explanation:\n";
    cout << "  Consider last bit of the bitstring:\n";
    cout << "  Case 1: Last bit is '1'\n";
    cout << "          → First (n-1) bits can be any valid string\n";
    cout << "          → B(n-1) possibilities\n\n";
    
    cout << "  Case 2: Last bit is '0'\n";
    cout << "          → Previous bit MUST be '1' (to avoid '00')\n";
    cout << "          → So last 2 bits are '10'\n";
    cout << "          → First (n-2) bits can be any valid string\n";
    cout << "          → B(n-2) possibilities\n\n";
    
    cout << "  Total: B(n) = B(n-1) + B(n-2)\n\n";
    
    cout << "Pattern:\n";
    cout << "  B(1) = 2   (strings: \"0\", \"1\")\n";
    cout << "  B(2) = 3   (strings: \"01\", \"10\", \"11\")\n";
    cout << "  B(3) = B(2) + B(1) = 3 + 2 = 5\n";
    cout << "  B(4) = B(3) + B(2) = 5 + 3 = 8\n";
    cout << "  B(5) = B(4) + B(3) = 8 + 5 = 13\n\n";
    
    cout << "This follows Fibonacci sequence with B(1)=2, B(2)=3!\n\n";
    
    cout << "Time Complexity:\n";
    cout << "  - Naive Recursion: O(2^n)\n";
    cout << "  - Iterative: O(n)\n";
    cout << "Space Complexity:\n";
    cout << "  - Naive: O(n) [recursion stack]\n";
    cout << "  - Iterative: O(1)\n\n";
}

// ============================================================
//  Display all valid bitstrings for small n
// ============================================================
void displaySmallCases() {
    cout << "========================================\n";
    cout << "  VALID BITSTRINGS (Small Cases)\n";
    cout << "========================================\n\n";
    
    for (int n = 1; n <= 5; n++) {
        cout << "n = " << n << ": " << countBitstrings_iterative(n) 
             << " valid strings\n";
        
        vector<string> bitstrings = getAllBitstrings(n);
        cout << "  Strings: ";
        for (int i = 0; i < bitstrings.size(); i++) {
            cout << bitstrings[i];
            if (i < bitstrings.size() - 1) cout << ", ";
        }
        cout << "\n\n";
    }
}

// ============================================================
//  Display sequence
// ============================================================
void displaySequence() {
    cout << "========================================\n";
    cout << "  COUNT FOR DIFFERENT n\n";
    cout << "========================================\n\n";
    
    cout << "   n  |  Count\n";
    cout << "  --------------\n";
    
    for (int i = 1; i <= 20; i++) {
        cout << "  " << (i < 10 ? " " : "") << i 
             << "  |  " << countBitstrings_iterative(i) << "\n";
    }
    cout << "\n";
}

// ============================================================
//  Verification (brute force check for small n)
// ============================================================
void verifyCount(int n) {
    if (n > 10) {
        cout << "Verification skipped for n > 10 (too many strings)\n";
        return;
    }
    
    cout << "========================================\n";
    cout << "  VERIFICATION (n = " << n << ")\n";
    cout << "========================================\n\n";
    
    // Generate all possible 2^n bitstrings
    int total = 1 << n;  // 2^n
    int valid = 0;
    
    cout << "All " << total << " possible bitstrings:\n";
    for (int i = 0; i < total; i++) {
        string s = "";
        int num = i;
        for (int j = 0; j < n; j++) {
            s = (char)('0' + (num % 2)) + s;
            num /= 2;
        }
        
        bool validFlag = isValidBitstring(s);
        if (validFlag) {
            valid++;
            cout << "  ✓ " << s << "\n";
        } else {
            cout << "  ✗ " << s << " (has consecutive 0s)\n";
        }
    }
    
    cout << "\nValid strings: " << valid << "\n";
    cout << "Expected: " << countBitstrings_iterative(n) << "\n";
    cout << "Match: " << (valid == countBitstrings_iterative(n) ? "YES" : "NO") << "\n\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "========================================\n";
    cout << "  Q3 - Problem 4: Bitstrings\n";
    cout << "  Without Consecutive Zeros\n";
    cout << "========================================\n\n";
    
    // Display analysis
    displayAnalysis();
    
    // Display small cases
    displaySmallCases();
    
    // Display sequence
    displaySequence();
    
    // Verify for n=4
    verifyCount(4);
    
    // Interactive test
    int n;
    cout << "Enter length of bitstring: ";
    cin >> n;
    
    if (n <= 0 || n > 60) {
        cout << "Please enter n between 1 and 60\n";
        return 1;
    }
    
    cout << "\nNumber of valid bitstrings of length " << n << ": " 
         << countBitstrings_iterative(n) << "\n";
    
    if (n <= 8) {
        cout << "\nAll valid bitstrings:\n";
        vector<string> bitstrings = getAllBitstrings(n);
        for (const string& s : bitstrings) {
            cout << "  " << s << "\n";
        }
    }
    cout << "\n";
    
    // Test multiple values
    cout << "========================================\n";
    cout << "  TEST CASES\n";
    cout << "========================================\n\n";
    
    int tests[] = {5, 10, 15, 20, 25, 30};
    for (int i = 0; i < 6; i++) {
        int test_n = tests[i];
        cout << "B(" << test_n << ") = " 
             << countBitstrings_iterative(test_n) << "\n";
    }
    
    return 0;
}
