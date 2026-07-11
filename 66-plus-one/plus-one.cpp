class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from the end (least significant digit)
        for (int i = n - 1; i >= 0; --i) {
            // If digit is less than 9, just increment and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // Otherwise, set to 0 and continue to handle carry
            digits[i] = 0;
        }

        // If we reach here, all digits were 9 (e.g., 999 -> 1000)
        // So we need to insert 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};