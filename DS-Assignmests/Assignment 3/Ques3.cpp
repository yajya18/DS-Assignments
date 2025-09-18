// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define SIZE 10

// class STACK
// {
// 	char arr[SIZE];
// 	int top;
	
// 	public:
// 	STACK()
// 	{
// 		top = -1;
// 	}
	
// 	void push(char val)
// 	{
// 		if(top == SIZE -1)
// 		{
// 			cout<<"stack is full"<<endl;
// 		}
// 		else
// 		{
// 			++top;
// 			arr[top] = val;
// 		}
// 	}
	
// 	char pop()
// 	{
// 		if(top == -1)
// 		{
// 			return '\0';
// 		}
// 		else
// 		{
// 			return arr[top--];
// 		}
// 	}
	
// 	bool isEmpty()
// 	{
// 	    return top == -1;
// 	}
// };
	
// bool isMatching(char open , char close)
// {
// 	return (open == '(' && close == ')') || 
// 		   (open == '{' && close == '}') || 
// 		   (open == '[' && close == ']');
// }


// int main()
// {
// 	STACK s;
// 	string val;
	
// 	cout<<"enter string:"<<endl;
// 	cin>>val;
	
// 	for(char ch : val)
// 	{
// 		if(ch == '(' || ch == '{' || ch == '[')
// 		{
// 			s.push(ch);
// 		}
// 		else if(ch == ')' || ch == '}' || ch == ']')
// 		{
// 			if(s.isEmpty())
// 			{
// 				cout<<"stack is empty"<<ch<<endl;
// 				return 0;
// 			}
			
// 			char popped = s.pop();
			
// 			if(!isMatching(popped , ch))
// 			{
// 			    cout<<"Unmatched brackets "<<popped<<" and "<<ch<<endl;
// 			    return 0;
// 			}
// 		}
// 	}
	
// 	if(s.isEmpty())
// 	{
// 		cout<<"balanced brackets"<<endl;
// 	}
// 	else
// 	{
// 		cout<<"unbalanced brackets:extra brackets"<<endl;
// 	}
// }


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

char pop(){
    if(isEmpty()){
        cout<<"Underflow condition";
    }
    else{
        return stack[top--];
    }
}

int main() {
	top=-1;
	string str;
	int count1,count2;
	cout<<"Enter the expression: ";
	getline(cin, str);
	for(int i=0;i<str.length();i++){
		if(str[i]=='('||str[i]=='['||str[i]=='{'){
			push(str[i]);
			count1++;
		}
	}
	for(int i=0;i<str.length();i++){
		if(str[i]==')'||str[i]==']'||str[i]=='}'){
			if(pop()==str[i]){
				count2++;
			}
		}
	}
	if(count1==count2){
		cout<<"Balanced brackets\n";
	}
	else{
		cout<<"Unbalanced brackets";
	}
	return 0;
}