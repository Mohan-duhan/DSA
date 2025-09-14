class Solution {
public:
    static bool compare(const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second == b.second) 
            return a.first > b.first;   // same freq → larger value first
        return a.second < b.second;     // smaller freq first
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;

        for (int i : nums) {
            freq[i]++;
        }

        vector<pair<int,int>> res(freq.begin(), freq.end());

        sort(res.begin(), res.end(), compare);

        vector<int> ans;
        for (int i = 0; i < res.size(); i++) {
            while (res[i].second-- > 0) {
                ans.push_back(res[i].first);
            }
        }
        return ans;
    }
};
