class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int currentSum = 0;
     int maxSum = nums[0];
     for(int i = 0;i<nums.size();i++){
        if(currentSum+nums[i]<nums[i]){
            currentSum = nums[i];
        }
        else{
            currentSum = currentSum+nums[i];
        }
        if(currentSum>maxSum){
            maxSum = currentSum;
        }
     }
     return maxSum;
    }
};
