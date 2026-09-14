class Solution {
public:
    // LeetCode expects the function with exactly these two parameters
    int longestCommonSubsequence(const string &text1, const string &text2) {
        int m = text1.size();
        int n = text2.size();

        // Can't use int t[m+1][n+1] on LeetCode (VLA not allowed) → use vector
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        // fill DP table (your logic unchanged)
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        return t[m][n];
    }
};
