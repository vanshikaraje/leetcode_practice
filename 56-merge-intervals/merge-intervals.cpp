class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
   vector<vector<int>> ans;

    // Step 1: Sort intervals
    sort(intervals.begin(), intervals.end());

    // Step 2: Add the first interval
    ans.push_back(intervals[0]);

    // Step 3: Check remaining intervals
    for (int i = 1; i < intervals.size(); i++) {

        vector<int> current = intervals[i];

        // Last interval in answer
        vector<int>& last = ans.back();

        // Overlap
        if (current[0] <= last[1]) {
            last[1] = max(last[1], current[1]);
        }

        // No overlap
        else {
            ans.push_back(current);
        }
    }

    return ans;
}

};