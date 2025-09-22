class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<int> ans;

        for (auto& it : mp) {
            if (it.second == 1 and mp.find(it.first + 1) == mp.end() and
                mp.find(it.first - 1) == mp.end()) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};