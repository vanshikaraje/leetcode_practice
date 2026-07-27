class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];
        for(int i =1;i<nums.size();i++){
            int current = nums[i];
            int tempmax = maxprod;
            maxprod = max({current,tempmax*current,minprod*current});
            minprod = min({current,tempmax*current,minprod*current});
            ans = max(ans,maxprod);
        }
        return ans;
    }
};