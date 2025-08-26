#include<iostream>
#include<vector>
using namespace std;
#define n 6

class Stack{
	int arr[n];
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
		
		void push(int val){
			if(isFull()){
				cout << "Stack Overflow! Cannot push" << endl;
			}
			else{
				arr[++top] = val;
			}
		}
		
		void pop(){
			if(isEmpty()){
				cout << "Stack Underflow! Cannot pop." << endl;
			}
			else{
				arr[top--];
			}
		}
		
		void peek(){
			if(isEmpty()){
				cout << "Stack empty!" << endl;
			}
			else {
				cout << "top element : "<< arr[top] << endl;
			}
		}
		
		void display(){
			if(isEmpty()){
				cout << "Stack is Empty !" << endl;
			}
			else {
				cout << "Stack elements : "<< endl;
				for(int i=top; i>=0; i--){
					cout << arr[i] << endl;
				}
			}
			cout << endl;
		}
		
};

int main(){
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.display();
	s1.pop();
	s1.display();
	s1.peek();
	
	
	return 0;
}
