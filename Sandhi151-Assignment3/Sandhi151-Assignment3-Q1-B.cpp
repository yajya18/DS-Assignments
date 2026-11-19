/*
 * ============================================================
 *  Sandhi151 | DSA Lab | Assignment 3
 *  Q1-B : Long Addition of Two Large Numbers Using Arrays
 * ============================================================
 *  Problem:
 *   Add two numbers whose digit count is between 100 and 10000.
 *   Since these numbers are too big for int/long long, we store
 *   each digit in an array and add digit-by-digit (like we do
 *   on paper), handling the carry at each step.
 *
 *  Steps:
 *   1. Store digits of each number in an int array (LSD first).
 *   2. Add corresponding digits + carry from right to left.
 *   3. Store result in a new array and print it.
 * ============================================================
 */

#include <iostream>
#include <cstdlib>      // malloc, calloc, free
#include <cstring>      // strlen
using namespace std;

/* ============================================================
   digitLength  –  count digits in a numeric string
   ============================================================ */
int digitLength(const char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

/* ============================================================
   addLargeNumbers
   num1, num2  : numeric strings (digits only, no sign)
   Returns     : malloc-allocated char string of the result.
                 Caller must free().
   ============================================================ */
char* addLargeNumbers(const char* num1, const char* num2) {
    int len1 = digitLength(num1);
    int len2 = digitLength(num2);
    int maxLen = (len1 > len2) ? len1 : len2;

    // calloc: digit arrays initialised to 0
    int* d1 = (int*) calloc(maxLen + 1, sizeof(int));
    int* d2 = (int*) calloc(maxLen + 1, sizeof(int));
    int* res = (int*) calloc(maxLen + 2, sizeof(int)); // +2 for possible carry

    // Fill d1 in reverse (index 0 = least significant digit)
    for (int i = 0; i < len1; i++)
        d1[i] = num1[len1 - 1 - i] - '0';

    // Fill d2 in reverse
    for (int i = 0; i < len2; i++)
        d2[i] = num2[len2 - 1 - i] - '0';

    // Add digit by digit
    int carry = 0;
    for (int i = 0; i <= maxLen; i++) {
        int sum  = d1[i] + d2[i] + carry;
        res[i]   = sum % 10;
        carry    = sum / 10;
    }

    // Find actual length of result
    int resLen = maxLen + 1;
    while (resLen > 1 && res[resLen - 1] == 0)
        resLen--;

    // Build result string (malloc)
    char* resultStr = (char*) malloc((resLen + 1) * sizeof(char));
    for (int i = 0; i < resLen; i++)
        resultStr[i] = '0' + res[resLen - 1 - i]; // most significant first
    resultStr[resLen] = '\0';

    free(d1);
    free(d2);
    free(res);

    return resultStr;
}

/* ============================================================
   MAIN
   ============================================================ */
int main() {
    cout << "========================================\n";
    cout << "   Q1-B: Long Addition of Large Numbers\n";
    cout << "========================================\n\n";

    // --- Test Case 1: small numbers to verify correctness ---
    cout << "-- Test 1: Small numbers --\n";
    const char* n1 = "12345";
    const char* n2 = "98765";
    char* ans = addLargeNumbers(n1, n2);
    cout << "  " << n1 << "\n+ " << n2 << "\n= " << ans << "\n\n";
    free(ans);

    // --- Test Case 2: numbers with different lengths ---
    cout << "-- Test 2: Different lengths --\n";
    const char* n3 = "999";
    const char* n4 = "1";
    ans = addLargeNumbers(n3, n4);
    cout << "  " << n3 << "\n+ " << n4 << "\n= " << ans << "\n\n";
    free(ans);

    // --- Test Case 3: 100-digit numbers ---
    cout << "-- Test 3: 100-digit numbers --\n";
    // 100 nines
    char big1[101], big2[101];
    for (int i = 0; i < 100; i++) { big1[i] = '9'; big2[i] = '1'; }
    big1[100] = big2[100] = '\0';
    big2[99] = '0'; // make big2 = 10000...0 (1 followed by 99 zeros in reverse logic)

    ans = addLargeNumbers(big1, big2);
    cout << "  First  number (100 digits): 9999...9 (100 nines)\n";
    cout << "  Second number (100 digits): 1000...0 (1 then 99 zeros)\n";
    cout << "  Result: " << ans << "\n\n";
    free(ans);

    // --- Test Case 4: very large (200-digit) numbers ---
    cout << "-- Test 4: 200-digit numbers --\n";
    // malloc to create 200-digit strings
    char* big3 = (char*) malloc(201 * sizeof(char));
    char* big4 = (char*) malloc(201 * sizeof(char));

    for (int i = 0; i < 200; i++) { big3[i] = '5'; big4[i] = '5'; }
    big3[200] = big4[200] = '\0';

    ans = addLargeNumbers(big3, big4);
    cout << "  Two 200-digit numbers (all 5s) added:\n";
    cout << "  Result = " << ans << "\n\n";
    free(big3);
    free(big4);
    free(ans);

    cout << "Note: This approach works for numbers up to 10000 digits.\n";

    return 0;
}
