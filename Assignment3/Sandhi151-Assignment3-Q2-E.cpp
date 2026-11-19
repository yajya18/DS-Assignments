// Name: Sandhi Gahlot
// Roll No: 1024150151
// Acknowledgement: GeeksForGeeks

#include <iostream>
using namespace std;

int max(int arr[], int size) {
    if (size <= 0) return -1;

    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;
    int result = max(arr, size);
    cout << "Maximum element in the array is: " << result << endl;
    return 0;
}