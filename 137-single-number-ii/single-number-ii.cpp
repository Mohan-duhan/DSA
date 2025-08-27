class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        for (auto& p : freq) {
            if (p.second == 1) {
                ans = p.first;
            }
        }

        return ans;
    }
};
