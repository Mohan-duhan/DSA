class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total_pairs = n * (n - 1) / 2;
        long long good_pairs = 0;

        unordered_map<long long, long long> freq;

        for (int i = 0; i < n; i++) {
            long long key = (long long)nums[i] - i;
            good_pairs += freq[key];
            freq[key]++;
        }
        return total_pairs - good_pairs;
    }
};
