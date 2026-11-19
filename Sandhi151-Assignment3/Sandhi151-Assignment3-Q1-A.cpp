/*
 * ============================================================
 *  Sandhi151 | DSA Lab | Assignment 3
 *  Q1-A : Advanced Operations on a One-Dimensional Array
 * ============================================================
 *  Functions implemented:
 *   1. isSorted              - check if array is sorted
 *   2. mergeArrays           - merge two arrays
 *   3. unionArrays           - set union (loop)
 *   4. intersectionArrays    - set intersection (loop)
 *   5. findDupSorted         - duplicates in sorted array
 *   6. findDupUnsorted       - duplicates in unsorted array
 *   7. findPairSum           - pair with sum k  (unsorted)
 *   8. findPairSumSorted     - pair with sum k  (sorted, two-pointer)
 *   9. findMaxMin            - max and min in single scan
 * ============================================================
 */

#include <iostream>
#include <cstdlib>      // malloc, calloc, free
using namespace std;

/* ---------- helper: print an array ---------- */
void printArr(int* arr, int n, const char* label) {
    cout << label << ": [ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n-1 ? ", " : " ");
    cout << "]\n";
}

/* ============================================================
   1. isSorted
   Returns true if array is sorted in non-decreasing order.
   ============================================================ */
bool isSorted(int* arr, int n) {
    if (n <= 1) return true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

/* ============================================================
   2. mergeArrays
   Merges array a (size n) and array b (size m) into a new
   array using malloc.  Caller must free() the result.
   outSize is set to n + m.
   ============================================================ */
int* mergeArrays(int* a, int n, int* b, int m, int& outSize) {
    outSize = n + m;
    int* merged = (int*) malloc(outSize * sizeof(int));

    for (int i = 0; i < n; i++)      merged[i]     = a[i];
    for (int i = 0; i < m; i++)      merged[n + i] = b[i];

    return merged;
}

/* ============================================================
   3a. unionArrays
   Returns the set-union of a and b (no duplicates).
   Uses calloc. Caller must free() the result.
   ============================================================ */
int* unionArrays(int* a, int n, int* b, int m, int& outSize) {
    // worst case: all elements are unique => n + m
    int* result = (int*) calloc(n + m, sizeof(int));
    outSize = 0;

    // add every element of a (skip if already added)
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < outSize; j++)
            if (result[j] == a[i]) { found = true; break; }
        if (!found) result[outSize++] = a[i];
    }

    // add every element of b (skip if already in result)
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < outSize; j++)
            if (result[j] == b[i]) { found = true; break; }
        if (!found) result[outSize++] = b[i];
    }

    return result;
}

/* ============================================================
   3b. intersectionArrays
   Returns elements common to both a and b (no duplicates).
   Uses calloc. Caller must free() the result.
   ============================================================ */
int* intersectionArrays(int* a, int n, int* b, int m, int& outSize) {
    int maxSz = (n < m) ? n : m;
    int* result = (int*) calloc(maxSz, sizeof(int));
    outSize = 0;

    for (int i = 0; i < n; i++) {
        // check if a[i] is present in b
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                // check not already added
                bool already = false;
                for (int k = 0; k < outSize; k++)
                    if (result[k] == a[i]) { already = true; break; }
                if (!already) result[outSize++] = a[i];
                break;
            }
        }
    }

    return result;
}

/* ============================================================
   4. findDupSorted
   In a sorted array, duplicates appear consecutively.
   Returns malloc-allocated list of duplicate values.
   Caller must free() the result.
   ============================================================ */
int* findDupSorted(int* arr, int n, int& outSize) {
    int* dups = (int*) malloc(n * sizeof(int));
    outSize = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            // add to dups only once per value
            bool already = false;
            for (int j = 0; j < outSize; j++)
                if (dups[j] == arr[i]) { already = true; break; }
            if (!already) dups[outSize++] = arr[i];
        }
    }

    return dups;
}

/* ============================================================
   5. findDupUnsorted
   Compare every pair to detect duplicates (O(n^2)).
   Returns calloc-allocated list. Caller must free() the result.
   ============================================================ */
int* findDupUnsorted(int* arr, int n, int& outSize) {
    int* dups = (int*) calloc(n, sizeof(int));
    outSize = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                bool already = false;
                for (int k = 0; k < outSize; k++)
                    if (dups[k] == arr[i]) { already = true; break; }
                if (!already) dups[outSize++] = arr[i];
                break;
            }
        }
    }

    return dups;
}

/* ============================================================
   6. findPairSum  (unsorted array – brute force O(n^2))
   Prints all pairs (a[i], a[j]) whose sum equals k.
   ============================================================ */
void findPairSum(int* arr, int n, int k) {
    cout << "  Pairs with sum " << k << ": ";
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                cout << "(" << arr[i] << "," << arr[j] << ") ";
                found = true;
            }
        }
    }
    if (!found) cout << "None";
    cout << "\n";
}

/* ============================================================
   7. findPairSumSorted  (sorted array – two-pointer O(n))
   Prints all pairs whose sum equals k.
   ============================================================ */
void findPairSumSorted(int* arr, int n, int k) {
    int left  = 0;
    int right = n - 1;
    bool found = false;

    cout << "  Pairs with sum " << k << " (two-pointer): ";
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) {
            cout << "(" << arr[left] << "," << arr[right] << ") ";
            found = true;
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
    if (!found) cout << "None";
    cout << "\n";
}

/* ============================================================
   8. findMaxMin  (single scan O(n))
   Finds maximum and minimum in one loop pass.
   ============================================================ */
void findMaxMin(int* arr, int n, int& maxVal, int& minVal) {
    if (n == 0) { maxVal = minVal = 0; return; }
    maxVal = minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if      (arr[i] > maxVal) maxVal = arr[i];
        else if (arr[i] < minVal) minVal = arr[i];
    }
}

/* ============================================================
   MAIN
   ============================================================ */
int main() {
    cout << "========================================\n";
    cout << "   Q1-A: 1D Array Operations\n";
    cout << "========================================\n\n";

    // ---- test arrays ----
    int a[]     = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n       = 9;
    int sorted1[] = {1, 2, 3, 4, 5, 6};
    int m1 = 6;
    int sorted2[] = {2, 3, 4, 5, 7, 8};
    int m2 = 6;
    int dupSorted[] = {1, 1, 2, 3, 3, 4, 5, 5};
    int nd = 8;

    // ---- 1. isSorted ----
    cout << "-- 1. isSorted --\n";
    printArr(a, n, "Array");
    cout << "  Is sorted? " << (isSorted(a, n) ? "YES" : "NO") << "\n";
    printArr(sorted1, m1, "Array");
    cout << "  Is sorted? " << (isSorted(sorted1, m1) ? "YES" : "NO") << "\n\n";

    // ---- 2. mergeArrays ----
    cout << "-- 2. mergeArrays --\n";
    int b[] = {10, 20, 30};
    int mb  = 3;
    int mergedSize;
    int* merged = mergeArrays(a, n, b, mb, mergedSize);
    printArr(a,      n,          "Array A");
    printArr(b,      mb,         "Array B");
    printArr(merged, mergedSize, "Merged ");
    free(merged);
    cout << "\n";

    // ---- 3a. union ----
    cout << "-- 3a. Union --\n";
    int x[] = {1, 2, 3, 4, 5};
    int y[] = {3, 4, 5, 6, 7};
    int nx = 5, ny = 5, uSize;
    int* uni = unionArrays(x, nx, y, ny, uSize);
    printArr(x,   nx,    "Array X");
    printArr(y,   ny,    "Array Y");
    printArr(uni, uSize, "Union  ");
    free(uni);
    cout << "\n";

    // ---- 3b. intersection ----
    cout << "-- 3b. Intersection --\n";
    int iSize;
    int* inter = intersectionArrays(x, nx, y, ny, iSize);
    printArr(inter, iSize, "Intersection");
    free(inter);
    cout << "\n";

    // ---- 4. duplicates in sorted ----
    cout << "-- 4. Duplicates in Sorted Array --\n";
    printArr(dupSorted, nd, "Sorted Array");
    int dSize;
    int* dups = findDupSorted(dupSorted, nd, dSize);
    printArr(dups, dSize, "Duplicates  ");
    free(dups);
    cout << "\n";

    // ---- 5. duplicates in unsorted ----
    cout << "-- 5. Duplicates in Unsorted Array --\n";
    printArr(a, n, "Unsorted Array");
    int uDupSize;
    int* uDups = findDupUnsorted(a, n, uDupSize);
    printArr(uDups, uDupSize, "Duplicates    ");
    free(uDups);
    cout << "\n";

    // ---- 6. pair with sum k (unsorted) ----
    cout << "-- 6. Pair with Sum k (unsorted) --\n";
    int arr2[] = {8, 7, 2, 5, 3, 1};
    int n2 = 6;
    printArr(arr2, n2, "Array");
    findPairSum(arr2, n2, 10);
    cout << "\n";

    // ---- 7. pair with sum k (sorted, two-pointer) ----
    cout << "-- 7. Pair with Sum k (sorted) --\n";
    int sortedArr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int ns = 8;
    printArr(sortedArr, ns, "Sorted Array");
    findPairSumSorted(sortedArr, ns, 9);
    cout << "\n";

    // ---- 8. max and min ----
    cout << "-- 8. Max and Min in Single Scan --\n";
    printArr(a, n, "Array");
    int maxV, minV;
    findMaxMin(a, n, maxV, minV);
    cout << "  Max = " << maxV << "  |  Min = " << minV << "\n\n";

    return 0;
}
