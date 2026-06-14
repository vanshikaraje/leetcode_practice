class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<int> st; // stores indices

        for (int i = n - 1; i >= 0; i--) {

            // remove all days which are not warmer
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // if stack is not empty, next warmer day exists
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // push current index
            st.push(i);
        }

        return ans;
    }
};