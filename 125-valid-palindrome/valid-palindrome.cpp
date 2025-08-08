class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (isalnum(ch)) {
                ans += ch;
            }
        }
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        int start = 0;
        int end = ans.size() - 1;
        while (start < end) {
            if (ans[start] != ans[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};