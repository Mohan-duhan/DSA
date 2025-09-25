class Solution {
public:
    vector<vector<int>> res;

    void solve(int val, int k, vector<int>& temp, int n) {
        if (k == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = val; i <= n; i++) {
            temp.push_back(i);               // choose i
            solve(i + 1, k - 1, temp, n);    // move forward
            temp.pop_back();                 // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, k, temp, n);
        return res;
    }
};
