#include<iostream>
#include<stack>              
using namespace std; 

bool isValidParentheses(string s){
	stack<char> st;
		
	for(int i=0; i<s.size(); i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			st.push(s[i]);    //for opening brackets
		}
		else {
			if(st.size() == 0){ //if i points to closing bracket and stack is empty
				return false;    // {[()]}]  last ']' is extra one
			}
			if(st.top() == '(' && s[i] == ')' ||
			st.top() == '{' && s[i] == '}' ||    //if matched, pop from stack so that 
			st.top() == '[' && s[i] == ']' ){   // we will be able to check for next bracket
			   	st.pop();                      // that if they are in order
			}
			else {
			   	return false; //brackets not matched return false
			}
		}
	}
	return st.size()==0;
}

int main(){
	string s;
	cout << "Enter string'(',')','{','}','[',']' : "; 
	cin >> s;
	if(isValidParentheses(s)) {
		cout << "It is Valid." << endl;
	}
	else{
		cout << "Not Valid." << endl;
	}
	return 0;
}

