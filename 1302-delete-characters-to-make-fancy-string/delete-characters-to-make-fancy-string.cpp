class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count = 1;

        ans.push_back(s[0]); 

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count < 3) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};
