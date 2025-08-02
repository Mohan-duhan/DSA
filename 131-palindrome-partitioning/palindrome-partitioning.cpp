class Solution {
public:
    bool isPalindrome(string str) {
        string r_str = str;
        reverse(r_str.begin(), r_str.end());
        return r_str == str;
    }

    void solve(string s, int idx, vector<string> curr, vector<vector<string>>& res) {
        if (idx == s.length()) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            string part = s.substr(idx, i - idx + 1);
            if (isPalindrome(part)) {
                curr.push_back(part);
                solve(s, i + 1, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        solve(s, 0, curr, res);
        return res;
    }
};
