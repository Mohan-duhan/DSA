class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> seen;
        int i = 0, j = 0;
        int max_len = 0;

        while (j < n) {
            if (!seen.count(s[j])) {
                seen.insert(s[j]);
                max_len = max(max_len, j - i + 1);
                j++;
            } else {
                seen.erase(s[i]);
                i++;
            }
        }

        return max_len;
    }
};
