class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {

        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        // Build LCS table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        // Build SCS using backtracking
        string ans = "";

        int i = m;
        int j = n;

        while (i > 0 && j > 0) {

            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
            }
            else if (t[i - 1][j] > t[i][j - 1]) {
                ans += s1[i - 1];
                i--;
            }
            else {
                ans += s2[j - 1];
                j--;
            }
        }

        // Remaining characters
        while (i > 0) {
            ans += s1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += s2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};