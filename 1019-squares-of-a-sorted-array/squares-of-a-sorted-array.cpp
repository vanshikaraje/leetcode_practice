// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0;i<nums.size();i++){
//           nums[i] = nums[i]*nums[i];
//         }
//         sort(nums.begin(),nums.end());return nums;

//     }
// };
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int left = 0;
        int right = n-1;
        int k = n-1;
        while(left<=right){
         int leftsq = nums[left]*nums[left];
         int rightsq = nums[right]*nums[right];
         if(leftsq>rightsq){
            ans[k]=leftsq;
            left++;
         }
         else{
            ans[k]=rightsq;
            right--;
         }
         k--;
        }
        return ans;
    }
};