class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans = n * (n - 1) / 2;

        unordered_map<long long, long long> freq;

        for (int i = 0; i < n; i++) {
            long long key = (long long)nums[i] - i;
            ans -= freq[key];
            freq[key]++;
        }
        return ans;
    }
};
