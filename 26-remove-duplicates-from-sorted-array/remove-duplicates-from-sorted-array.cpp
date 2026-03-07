class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
if(nums.size()==0)return 0;
int n = nums.size();
int i = 0;
for(int j=1;j<n;j++){
if(nums[j]!=nums[i]){
    nums[i+1]=nums[j];
    i++;
}
}
return i+1;
    }
};
