class Solution {
public:
    void removeLastChar(string& result) {
        int len = result.size();
        if (len <= 1) {
            result = "";
        } else {
            result.erase(result.end() - 1);
        }
    }

    string processStr(string s) {
        int n = s.size();
        string result = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                removeLastChar(result);
            }
            else if (s[i] == '%') {
                reverse(result.begin(), result.end());
            }
            else if (s[i] == '#') {
                string temp = result;         
                result.append(temp); 
            }
            else {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};
