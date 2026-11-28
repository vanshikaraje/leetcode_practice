class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Make nums1 the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        // Binary search range
        int low = 0;
        int high = n1;

        // Total elements
        int total = n1 + n2;

        // Number of elements we want on LEFT
        int leftSize = (total + 1) / 2;

        while (low <= high) {

            // Cut in nums1
            int cut1 = (low + high) / 2;

            // Cut in nums2
            int cut2 = leftSize - cut1;

            // Elements just before the cuts
            int left1;
            int left2;

            if (cut1 == 0)
                left1 = INT_MIN;
            else
                left1 = nums1[cut1 - 1];

            if (cut2 == 0)
                left2 = INT_MIN;
            else
                left2 = nums2[cut2 - 1];


            // Elements just after the cuts
            int right1;
            int right2;

            if (cut1 == n1)
                right1 = INT_MAX;
            else
                right1 = nums1[cut1];

            if (cut2 == n2)
                right2 = INT_MAX;
            else
                right2 = nums2[cut2];


            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Odd number of elements
                if (total % 2 == 1) {
                    return max(left1, left2);
                }

                // Even number of elements
                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }


            // cut1 is too far RIGHT
            else if (left1 > right2) {
                high = cut1 - 1;
            }


            // cut1 is too far LEFT
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};