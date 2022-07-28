/* Double stack method

class MinStack {
public:
  stack<int> st;
  stack<int> history;
  MinStack() { history.push(INT_MAX); }

  void push(int val) {
    if (val <= history.top())
      history.push(val);
    st.push(val);
  }

  void pop() {
    if (st.top() == history.top())
      history.pop();
    st.pop();
  }

  int top() { return st.top(); }

  int getMin() { return history.top(); }
};
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Optimal method - one stack (refer to forum, it's so clever!)
class MinStack {
public:
  int minEle;
  stack<int> st;
  MinStack() { minEle = INT_MAX; }

  void push(int val) {
    if (val <= minEle) {
      st.push(minEle); // so the element below min is previous min
      minEle = val;
    }
    st.push(val);
  }

  void pop() {
    if (st.top() ==
        minEle) { // if the top is min, pop update min to previous min
      st.pop();
      minEle = st.top();
    }
    st.pop();
  }

  int top() { return st.top(); }

  int getMin() { return minEle; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
