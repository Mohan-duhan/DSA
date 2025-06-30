class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0, maxLen = 0;

        for (int i = 0; i < n; ++i) {
            while (nums[i] - nums[start] > 1) {
                start++;
            }
            if (nums[i] - nums[start] == 1) {
                maxLen = max(maxLen, i - start + 1);
            }
        }

        return maxLen;
    }
};
