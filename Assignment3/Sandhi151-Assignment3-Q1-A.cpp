// Name: Sandhi Gahlot
// Roll No: 1024150151
// Acknowledgement: GeeksForGeeks

#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[10] = {1,2,3,4};
    int size=4;
    cout<<"Enter the element you want to insert: "<<endl;
    cin>>n;

    for(int i=size; i>0; i--) arr[i] = arr[i-1];
    arr[0] = n;
    size++;

    // printing the array
    for(int i=0; i<size; i++)cout<<arr[i]<<"\t";

    return 0;
}