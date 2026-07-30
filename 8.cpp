class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            int a = nums[i];
            int t = nums[a] % n; 
            nums[i] = a + n * t;
        }
        for (int i = 0; i < n; ++i){
            nums[i] /= n;
        }
        return nums;
    }
};
