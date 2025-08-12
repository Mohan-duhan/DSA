class Solution {
public:
    const int MOD = 1e9 + 7;

    int rev(int n) {
        int rev_num = 0;
        while (n > 0) {
            int last_digit = n % 10;
            rev_num = rev_num * 10 + last_digit;
            n = n / 10;
        }
        return rev_num;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int a = rev(nums[i]);
            int key = nums[i] - a;
            count = (count + mp[key]) % MOD;
            mp[key]++;
        }
        return count % MOD;
    }
};