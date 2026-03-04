class Solution {
public:
    bool subsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>>t(n+1,vector<bool>(target+1,false));
        for(int i = 0;i<=n;i++){
            t[i][0]=true;
        }
        for(int j = 1;j<=target;j++){
            t[0][j]=false;
        }
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
    bool canPartition(vector<int>& nums){
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2!=0){
            return false;
        }
        return subsetSum(nums,sum/2);
    }
};
