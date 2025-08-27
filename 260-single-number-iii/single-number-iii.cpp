class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        for (auto &p : freq) { 
            if (p.second == 1) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
