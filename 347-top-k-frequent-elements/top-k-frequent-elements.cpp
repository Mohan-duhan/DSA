class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int, int>> pairs;

        for (int num : nums) {
            mp[num]++;
        }

        for (auto& it : mp) {
            pairs.push_back({it.second, it.first});
        }

        sort(pairs.rbegin(), pairs.rend());

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pairs[i].second);
        }

        return res;
    }
};
