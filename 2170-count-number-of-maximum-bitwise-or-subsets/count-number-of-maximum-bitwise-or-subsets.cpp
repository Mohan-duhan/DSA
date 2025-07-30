class Solution {
public:
    int solve(vector<int> nums, int idx, int curr_or, int max_or) {
        if (idx == nums.size()) {
            if (curr_or == max_or)
                return 1;
            else {
                return 0;
            }
        }
        return solve(nums, idx + 1, curr_or | nums[idx], max_or) +
               solve(nums, idx + 1, curr_or, max_or);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int max_or = 0;
        for (int i = 0; i < n; i++) {
            max_or |= nums[i];
        }

        return solve(nums, 0, 0, max_or);
    }
};