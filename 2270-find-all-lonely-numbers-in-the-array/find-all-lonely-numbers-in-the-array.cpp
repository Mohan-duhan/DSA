class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        vector<int> freq(max_val + 1, 0);

        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans;
        for (int num : nums) {
            if (freq[num] == 1 &&
                (num == 0 || freq[num - 1] == 0) &&
                (num == max_val || freq[num + 1] == 0)) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
