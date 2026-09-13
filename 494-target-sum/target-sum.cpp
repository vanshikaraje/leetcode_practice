class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int total = 0;

        // Calculate total sum
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        // Target possible nahi hai
        if (target > total || target < -total) {
            return 0;
        }

        // Target Sum -> Count Subset Sum
        if ((total + target) % 2 != 0) {
            return 0;
        }

        int sum = (total + target) / 2;

        // Standard DP
        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(sum + 1, 0)
        );

        // Base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {

                if (nums[i - 1] <= j) {
                    dp[i][j] =
                        dp[i - 1][j] +
                        dp[i - 1][j - nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};