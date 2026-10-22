class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool forward = true, backward = true;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;

            if (nums[next] != (nums[i] + 1) % n)
                forward = false;

            if (nums[next] != (nums[i] - 1 + n) % n)
                backward = false;
        }

        if (!forward && !backward)
            return -1;

        if (forward)
            return min(pos, n - pos + 2);

        return min(n - pos, pos + 2);
    }
};