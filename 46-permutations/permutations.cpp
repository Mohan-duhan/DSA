class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, int i, int n) {
        if (i == n) {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            solve(nums, res, i + 1, n);
            swap(nums[i], nums[j]); // backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        solve(nums, res, 0, n);
        return res;
    }
};