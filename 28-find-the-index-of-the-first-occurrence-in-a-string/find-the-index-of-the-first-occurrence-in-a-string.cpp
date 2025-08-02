class Solution {
public:
    int strStr(string s1, string s2) {
        int n = s1.size();
        int k = s2.size();

        for (int i = 0; i <= n - k; i++) {
            int j = 0;
            while (j < k && s1[i + j] == s2[j]) {
                j++;
            }
            if (j == k)
                return i;
        }
        return -1;
    }
};