class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while (s.length() < k) {
            int n = s.length();

            for (int i = 0; i < n; i++) {
                char ch = s[i] == 'z'
                              ? 'a'
                              : s[i] + 1; // agar 'z' aajaye toh uska next char
                                          // 'a' hoga otherwise string me append
                                          // karte raho uske next element ko.
                s.push_back(ch);
            }
        }
        return s[k - 1];
    }
};