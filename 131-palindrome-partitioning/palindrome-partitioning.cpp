class Solution {
public:
    bool isPalindrome(const string& str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    }

    void solve(string& s, int idx, vector<string>& curr,
               vector<vector<string>>& res) {
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
