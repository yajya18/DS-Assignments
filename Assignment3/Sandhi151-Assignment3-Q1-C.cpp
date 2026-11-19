// Name: Sandhi Gahlot
// Roll No: 1024150151
// Acknowledgement: GeeksForGeeks

#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; 
    int size = 5;
    int element, pos;

    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position (0 to " << size-1 << "): ";
    cin >> pos;

    if (pos < 0 || pos > size)cout << "Invalid position! Must be between 0 and " << size << endl;
    else {
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = element;
        size++;

        // printing the array
        cout << "Array after insertion: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
    }

    return 0;
}
