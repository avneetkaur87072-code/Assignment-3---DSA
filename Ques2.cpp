#include<iostream>
#include<cstring>
using namespace std;
#define n 100


class Stack{
	char arr[n];
	int top;
	
	public:
		Stack(){
			top = -1;
		}
		bool isEmpty(){
			return top == -1;
		}
		
		bool isFull(){
			return top == n-1 ;
		}
		
		void push(char ch){
			if(isFull()){
				cout << "Stack Overflow!" << endl;
			}
			else {
				arr[++top] = ch;
			}
		}
		
		char pop(){
			if(isEmpty()){
				cout << "Stack Underflow!" <<endl;
			}
			else {
				return arr[top--];
			}
		}
		
		
};

int main(){
	Stack s;
	char str[n];
	
	cout << "Enter thr string : ";
	cin >> str;
	
	int len = strlen(str);
	
	for(int i=0; i<len; i++){
		s.push(str[i]);
	}
	
	cout << "Reversed String: " ;
	for(int i=0; i<len; i++){
		cout << s.pop();
	}
	cout << endl;
	
	
	return 0;
}
