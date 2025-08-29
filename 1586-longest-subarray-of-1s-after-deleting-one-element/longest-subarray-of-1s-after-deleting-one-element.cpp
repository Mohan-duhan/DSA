class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, count_zero = 0, max_len = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) count_zero++;

            while (count_zero > 1) {
                if (nums[i] == 0) count_zero--;
                i++;
            }
            max_len = max(max_len, j - i);
        }

        return max_len;
    }
};
