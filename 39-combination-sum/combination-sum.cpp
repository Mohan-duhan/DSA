class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int idx,
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0 || idx == candidates.size()) return;

        current.push_back(candidates[idx]);
        backtrack(candidates, target - candidates[idx], idx, current, result);
        current.pop_back();

        backtrack(candidates, target, idx + 1, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
