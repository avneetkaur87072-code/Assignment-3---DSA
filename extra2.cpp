#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
  private:
    stack<int> s;
    int minEle;
    
  public:
    SpecialStack() { //constructer
        minEle = -1;
    }
    
    
    void push(int x) {
        if (s.empty()) {    // Add an element to the top of Stack
            minEle = x;
            s.push(x);
        }
        else if (x < minEle) {   // If new number is less than minEle
            s.push(2 * x - minEle);  
            minEle = x;
        }
        else {
            s.push(x);
        }
        
    }
    
    
    void pop() {
        if (s.empty()) {
            return ;
        }
        
        int top = s.top();
        s.pop();
      
        if (top < minEle) {  // Minimum will change, if the minimum element, of the stack is being removed.
            minEle = 2 * minEle - top;
        }
    }
    
    
    int peek() {
        if (s.empty()) {
            return -1;
        }
        int top = s.top();

        // If minEle > top means minEle stores value of top.
        return (minEle > top) ? minEle : top;
    }
    
  
    int getMin() {
        if (s.empty())
            return -1;

        return minEle; //variable minEle stores the minimum element in the stack.
    }
};

int main() {
    SpecialStack ss;
    
    ss.push(2);
    ss.push(3);
    cout << ss.peek() << " ";
    ss.pop();
    cout << ss.getMin() << " ";
    ss.push(1);
    cout << ss.getMin() << " ";
}
