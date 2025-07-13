class Solution {
public:
    string processStr(string str) {
        int n = str.length();
        string result = "";

        for (int i = 0; i < n; i++) {
            char ch = str[i];

            if (islower(ch)) {
                result += ch;
            } else if (ch == '*') {
                if (!result.empty())
                    result.pop_back();
            } else if (ch == '#') {
                string temp = result;
                for (int i = 0; i < temp.length(); i++) {
                    result += temp[i];
                }
            } else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};
