class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int idx,
                   vector<int> check_comb, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(check_comb);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            check_comb.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, check_comb, res);
            check_comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> check_comb;
        backtrack(candidates, target, 0, check_comb, res);
        return res;
    }
};
