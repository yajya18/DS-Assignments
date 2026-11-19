// Name: Sandhi Gahlot
// Roll No: 1024150151
// Acknowledgement: GeeksForGeeks

#include <iostream>
using namespace std;

int set(int index, int value, int arr[], int size) {
    if (index >= 0 && index < size) {
        arr[index] = value;
        return 1;
    }
    return 0;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;
    int index, value;
    
    cout << "Enter the index to set: ";
    cin >> index;
    cout << "Enter the value to set: ";
    cin >> value;

    int result = set(index, value, arr, size);

    if (result == 1) {
        cout << "Value set successfully." << endl;
        cout << "Updated array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Failed to set value. Index is out of bounds." << endl;
    }

    return 0;
}