class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        // Step 1: insert all elements in set
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        int maxLen = 0;

        // Step 2: check only start points
        for(int num : st) {

            // start of sequence only
            if(st.find(num - 1) == st.end()) {

                int current = num;
                int count = 1;

                // expand sequence forward
                while(st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }

                if(count > maxLen) {
                    maxLen = count;
                }
            }
        }

        return maxLen;
    }
};