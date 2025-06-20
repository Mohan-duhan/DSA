class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n, 0);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 1 && nums[i] <= n) {
                freq[nums[i] - 1]++;
            }
        }

        int m = freq.size();

        for (int i = 0; i < m; i++) {
            if (freq[i] == 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
