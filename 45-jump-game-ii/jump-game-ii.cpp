class Solution {
public:
    int n;

    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= n - 1)
            return 0; 

        if (dp[idx] != -1)
            return dp[idx];

        int min_val = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++) {
            int res = solve(idx + i, nums, dp);
            if (res != INT_MAX) {
                min_val = min(min_val, 1 + res);
            }
        }
        return dp[idx] = min_val;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(0, nums, dp);
    }
};
