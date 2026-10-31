
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size(), n = grid[0].size();
        int sz = m * n;

        vector<int> right(sz, -1), down(sz, -1);

        // Precompute where a robot ends after entering a cell.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int id = i * n + j;

                if (grid[i][j] == 0) {
                    right[id] = down[id] = id;
                }
                else {
                    // Enter mirror while moving right:
                    // Reflect down.
                    if (i + 1 < m)
                        right[id] = down[id + n];

                    // Enter mirror while moving down:
                    // Reflect right.
                    if (j + 1 < n)
                        down[id] = right[id + 1];
                }
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;

                long long ways = dp[i][j];

                // Move right
                if (j + 1 < n) {
                    int dest = right[i * n + j + 1];

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;

                        dp[x][y] = (dp[x][y] + ways) % MOD;
                    }
                }

                // Move down
                if (i + 1 < m) {
                    int dest = down[(i + 1) * n + j];

                    if (dest != -1) {
                        int x = dest / n;
                        int y = dest % n;

                        dp[x][y] = (dp[x][y] + ways) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
