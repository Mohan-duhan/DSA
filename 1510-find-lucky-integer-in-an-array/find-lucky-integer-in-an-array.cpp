class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0);
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        int max_freq = -1;
        for (int i = 1; i < 501; i++) {
            if (freq[i] == i) {
                max_freq = max(max_freq, freq[i]);
            }
        }
        return max_freq;
    }
};