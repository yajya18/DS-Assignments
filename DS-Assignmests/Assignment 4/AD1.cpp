#include <iostream>
using namespace std;
void toBinary(int x){
        int binary[32];
        int i = 0;
        while(x>0){
            binary[i++] = x%2;
            x = x/2;
        }
        for(int j = i-1; j>=0; j--){
            cout<<binary[j];
        }
    }

void convert(int n){
    cout<<"Output: [";
    for(int i=1; i<=n; i++){
        toBinary(i);
        if(i != n){
            cout<<", ";
        }
    }
    cout<<"]";
}

int main() {
    int binary[32];
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;
    convert(n);
    return 0;
}