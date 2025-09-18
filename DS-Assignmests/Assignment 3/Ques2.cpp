#include <iostream>
#include<string>
#define MAX 100
using namespace std;

char stack[MAX];
int top;

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if(top == MAX-1){
        return true;
    }
    else{
        return false;
    }
}

void push(char value){
    if(isFull()){
        cout<<"Overflow condition";
    }
    else{
        stack[++top]=value;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Underflow condition";
    }
    else{
        cout<<stack[top--];
    }
}

void reverse(string str){
    for(int i=0;i<str.length();i++){
        push(str[i]);
    }
    for(int i=0;i<str.length();i++){
        pop();
    }
}

int main() {
    top=-1;
    string str;
    cout<<"Enter string: ";
    getline(cin, str);
    cout<<"The reversed string is: ";
    reverse(str);
    return 0;
}