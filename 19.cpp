class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        if (low == nums.end() || *low != target) {
            return {-1, -1};
        }
        auto high = upper_bound(nums.begin(), nums.end(), target);
        int first = distance(nums.begin(), low);
        int last = distance(nums.begin(), high) - 1;
        return {first, last};
    }
};
