class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            ans = max(ans, diff);
        }
        return ans;
    }
};