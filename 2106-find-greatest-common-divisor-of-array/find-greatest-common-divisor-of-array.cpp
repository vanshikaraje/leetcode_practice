class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = nums[0];
        int large = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            small = min(small, nums[i]);
            large = max(large, nums[i]);
        }

        return gcd(small, large);
    }
};