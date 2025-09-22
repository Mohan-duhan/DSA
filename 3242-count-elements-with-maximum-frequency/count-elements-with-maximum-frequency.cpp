class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101);
        int max_freq = 0;

        for (int num : nums) {
            freq[num]++;
            max_freq = max(max_freq, freq[num]);
        }
        int ans = 0;

        for (int x : freq) {
            if (x == max_freq) {
                ans += x;
            }
        }
        return ans;
    }
};