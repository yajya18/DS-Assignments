// Name: Sandhi Gahlot
// Roll No: 1024150151
// Acknowledgement: GeeksForGeeks

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; 
    int size = 5;
    int target;
    
    cout << "Enter the element to search: ";
    cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1)cout << "Element found at index: " << result << endl;
    else cout << "Element not found in the array." << endl;

    return 0;
}