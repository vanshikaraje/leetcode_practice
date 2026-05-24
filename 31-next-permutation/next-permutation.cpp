// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//        int n = nums.size();
//     int index = -1;

//     // Step 1: find pivot (first number from right which is smaller)
//     for (int i = n - 2; i >= 0; i--) {
//         if (nums[i] < nums[i + 1]) {
//             index = i;
//             break;
//         }
//     }

//     // If no pivot found, reverse whole array
//     if (index == -1) {
//         reverse(nums.begin(), nums.end());
//         return;
//     }

//     // Step 2: find the smallest number greater than nums[index]
//     for (int i = n - 1; i > index; i--) {
//         if (nums[i] > nums[index]) {
//             swap(nums[i], nums[index]);
//             break;
//         }
//     }

//     // Step 3: reverse the right part
//     reverse(nums.begin() + index + 1, nums.end());
// }
// };
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int index  =-1;
    int n = nums.size();

    //  for finding the pivot element
    for(int i = n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            index = i;
            break;
        }
    }
    // if pivot doesnot found
    if(index == -1){
        reverse(nums.begin(),nums.end());
        return ;
    }
    // find smallest elemet 
    for(int i = n-1;i>index;i--){
        if(nums[i]>nums[index]){
            swap(nums[i],nums[index]);
            break;
        }
    }
    reverse(nums.begin()+index+1,nums.end());
}
};