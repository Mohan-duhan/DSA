class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();

        int i = 0;
        while (i < n) {
            char ch = word[i];
            int cnt = 0;

            while (i < n && word[i] == ch) {
                i++;
                cnt++;
            }

            while (cnt > 0) {
                int take = min(9, cnt);
                comp += to_string(take) + ch;
                cnt -= take;
            }
        }
        return comp;
    }
};