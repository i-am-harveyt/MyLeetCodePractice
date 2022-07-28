class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ret = 0, a, b;
        stack<int> st;
        for (string token : tokens) {
            if (token == "+") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a+b);
            }
            else if (token == "-") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a-b);
            }
            else if (token == "*") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a*b);
            }
            else if (token == "/") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a/b);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
