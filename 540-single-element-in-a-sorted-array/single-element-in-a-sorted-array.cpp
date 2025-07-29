class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(100001, 0);

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};