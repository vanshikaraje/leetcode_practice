class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If closing bracket appears before matching opening
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check for correct bracket pairs
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If all opened brackets are closed
        return st.empty();
    }
};
