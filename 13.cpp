class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int left = 0;
        int right = height.size() - 1;
        int maxleft = 0;
        int maxright = 0;
        int totalwater = 0; 
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxleft) {
                    maxleft = height[left];
                } else {
                    totalwater += maxleft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxright) {
                    maxright = height[right];
                } else {
                    totalwater += maxright - height[right];
                }
                right--;
            }
        }
        return totalwater;
    }
};
