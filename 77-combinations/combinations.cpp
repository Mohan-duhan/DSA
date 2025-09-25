class Solution {
public:
    vector<vector<int>> res;
    void solve(int val, int k, vector<int>& temp, int n) {
        if (k == 0) {
            res.push_back(temp);
            return;
        }
        if (val > n)
            return;

        temp.push_back(val);
        solve(val + 1, k - 1, temp, n);

        temp.pop_back();
        solve(val + 1, k, temp, n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;

        solve(1, k, temp, n);
        return res;
    }
};