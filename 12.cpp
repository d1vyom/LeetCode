class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> ans(nums.begin(), nums.end());
        int i = 1;
        while (true) {
            if (ans.find(i) == ans.end()) {
                return i;
            }
            i++;
        }
    }
};
