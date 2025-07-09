class Solution {
public:
    void make_combinations(vector<int>& candidates, int target, int idx,
                           vector<int> check_comb, int total,
                           vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(check_comb);
            return;
        }

        if (total > target || idx >= candidates.size())
            return;

        check_comb.push_back(candidates[idx]);
        make_combinations(candidates, target, idx, check_comb,
                          total + candidates[idx], res);
        check_comb.pop_back();
        make_combinations(candidates, target, idx + 1, check_comb, total, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> check_comb;
        make_combinations(candidates, target, 0, check_comb, 0, res);
        return res;
    }
};