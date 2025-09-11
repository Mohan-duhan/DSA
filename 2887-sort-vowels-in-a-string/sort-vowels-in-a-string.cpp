class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
               ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {
        vector<char> ans;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                ans.push_back(s[i]);
            }
        }

        sort(ans.begin() , ans.end());
        
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = ans[idx++];
            }
        }
        return s;
    }
};