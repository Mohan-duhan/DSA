class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> pairs(mp.begin(), mp.end());
        sort(pairs.begin(), pairs.end(), compare);

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pairs[i].first);
        }

        return res;
    }
};
