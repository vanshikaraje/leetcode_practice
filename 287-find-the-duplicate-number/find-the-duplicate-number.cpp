class Solution {
public:
 int findDuplicate(vector<int>& nums) {
    unordered_set<int> seen;  // yeh hai register
    
    for (int num : nums) {        // har student check karo
        if (seen.count(num))      // pehle se register mein hai?
            return num;           // yahi duplicate hai!
        seen.insert(num);         // nahi tha toh register mein daalo
    }
    return -1;
}
};