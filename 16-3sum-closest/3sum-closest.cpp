class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2]; // 🔥 change 1

        for(int i = 0; i < nums.size(); i++){

            // ❌ remove this line (duplicate skip not needed)
            // if( i>0||nums[i]==nums[i-1])continue;

            int left = i+1;
            int right = nums.size()-1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];

                // 🔥 change 2 → update closest
                if(abs(target - sum) < abs(target - closest)){
                    closest = sum;
                }

                // 🔥 change 3 → pointer movement same
                if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }
                else{
                    return sum; // perfect match
                }
            }
        }
        return closest; // 🔥 change 4
    }
};