class Solution {
public:
    int strStr(string s1, string s2) {
        int n = s1.size();
        int k = s2.size();

        for (int i = 0; i <= n - k; i++) {
            if (s1.substr(i, k) == s2)
                return i;
        }
        return -1;
    }
};