class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();  // correct: use size of input string

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;  // can't match if stack is empty
                char ch = st.top();
                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == '}' && ch != '{') ||
                    (s[i] == ']' && ch != '[')) {
                    return false;
                }
                st.pop(); // only pop when it matches
            }
        }

        return st.empty();  // must be empty if all brackets matched
    }
};
