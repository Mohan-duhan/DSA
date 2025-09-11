class Solution {
public:
    void helper(unordered_map<int, int>::iterator it,
                unordered_map<int, int>::iterator ed, vector<int>& track,
                int target, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(track);
            return;
        }
        
        if (it == ed)
            return;

        // not take
        helper(next(it), ed, track, target, ans);

        // take i times
        int i;
        for (i = 0; i < it->second; i++) {
            track.push_back(it->first);
            target -= it->first;
            if (target >= 0)
                helper(next(it), ed, track, target, ans);

            else {
                i++;
                break;
            }
        }

        while (i--)
            track.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        // Note the frequency of the candidates
        unordered_map<int, int> mp;
        for (int x : can)
            mp[x]++;

        vector<vector<int>> ans;
        vector<int> track;

        helper(mp.begin(), mp.end(), track, target, ans);
        return ans;
    }
};