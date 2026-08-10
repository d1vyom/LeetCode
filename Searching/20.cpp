class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (n1 + n2 + 1) / 2 - partition1;
            int maxleft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minright1 = (partition1 == n1) ? INT_MAX : nums1[partition1];
            int maxleft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minright2 = (partition2 == n2) ? INT_MAX : nums2[partition2];
            
            if (maxleft1 <= minright2 && maxleft2 <= minright1) {
                if ((n1 + n2) % 2 != 0) {
                    return max(maxleft1, maxleft2);
                }
                return (max(maxleft1, maxleft2) + min(minright1, minright2)) / 2.0;
            }
            else if (maxleft1 > minright2) {
                high = partition1 - 1;
            }
            else {
                low = partition1 + 1;
            }
        }
        return 0.0;
    }
};
