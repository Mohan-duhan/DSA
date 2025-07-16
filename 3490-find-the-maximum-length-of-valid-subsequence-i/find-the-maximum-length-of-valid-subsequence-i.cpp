class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even_count = 0;
        int odd_count = 0;
        int count_parity = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even_count++;
                if (i != 0 && nums[i - 1] % 2 == 1)
                    count_parity++;
            } else {
                odd_count++;
                if (i != 0 && nums[i - 1] % 2 == 0)
                    count_parity++;
            }
        }
        return max({even_count, odd_count, count_parity});
    }
};