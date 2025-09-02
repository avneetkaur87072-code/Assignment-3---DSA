#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

bool canbesorted(vector<int>& A){
    int n = A.size();
    vector<int> target = A;
    sort(target.begin(), target.end());  
    
	stack<int> st;
	
	int j=0;
	
	for(int i=0; i<n; i++){
	    st.push(A[i]);
	    
	    while( !st.empty() && st.top() == target[j]){
	        st.pop();
	        j++;
	    }
	     
	}
	return j==n;
}
int main() {
   vector<int>A = {1,2,4,3};
   if(canbesorted(A)){
       cout << "Yes" << endl;
   }
   else {
       cout << "NO" << endl;
   }	
  return 0;
}

