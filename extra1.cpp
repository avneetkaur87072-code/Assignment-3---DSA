#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> G;
    stack<int> st;

    for (int i = 0; i < A.size(); i++) {
        // Pop elements that are >= current element
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        if (st.empty()) {
            G.push_back(-1);
        } else {
            G.push_back(st.top());
        }

        // Push current element into stack
        st.push(A[i]);
    }

    return G;
}


int main(){
	vector<int>A = {34, 35, 27, 42, 5, 28, 39, 20, 28};
	vector<int> ans = prevSmaller(A);
	for(int i : ans){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
