class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                cnt1++;
            } else {
                if (cnt1 > 0)
                    cnt1--;
                else
                    cnt2++;
            }
        }
        return cnt1 + cnt2;
    }
};