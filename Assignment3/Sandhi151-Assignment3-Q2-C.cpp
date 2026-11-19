// Name: Sandhi Gahlot
// Roll No: 1024150151
// Acknowledgement: GeeksForGeeks

#include <iostream>
using namespace std;

int get(int index, int arr[], int size) {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    return -1;
}
int main() {
    int arr[100] = {10, 20, 30, 40, 50}; 
    int size = 5;
    int index;
    
    cout << "Enter the index to retrieve: ";
    cin >> index;

    int result = get(index, arr, size);

    if (result != -1)cout << "Element at index " << index << " is: " << result << endl;
    else cout << "Index is out of bounds." << endl;

    return 0;
}