class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;

            int curr = max(pick, notPick);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};