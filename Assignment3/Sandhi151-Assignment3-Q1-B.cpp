// Name: Sandhi Gahlot
// Roll No: 1024150151
// Acknowledgement: GeeksForGeeks

#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size]{10, 20, 30, 40, 50};
    int newElement;
    cout<<"Enter the element you want to insert at the end: "<<endl;
    cin>>newElement;

    int* newArr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    newArr[size] = newElement;

    delete[] arr;
    arr = newArr;
    size++;

    for (int i = 0; i < size; i++) cout << arr[i] << "\t";
    
    delete[] arr;
    return 0;
}
