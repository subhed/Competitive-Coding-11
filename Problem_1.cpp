// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: Evaluate Reverse Polish Notation
// Approach: Stack
// Time Complexity: O(n) 
// Space Complexity: O(n)

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
    
            // Base
            if (tokens.size() == 0) {
                return 0;
            }
    
            stack<int> st;
    
            for (int i = 0; i < tokens.size(); i++) {
                // Logic
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                    tokens[i] == "/") {
                    // Individual Operations
                    if (!st.empty()) {
                        int second = st.top();
                        st.pop();
    
                        int first = st.top();
                        st.pop();
    
                        if (tokens[i] == "+") {
                            st.push(first + second);
                        } else if (tokens[i] == "-") {
                            st.push(first - second);
                        } else if (tokens[i] == "*") {
                            st.push(first * second);
                        } else if (tokens[i] == "/") {
                            st.push(first / second);
                        }
                    }
                } else {
                    st.push(stoi(tokens[i]));
                }
            }
    
            return st.top();
        }
    };