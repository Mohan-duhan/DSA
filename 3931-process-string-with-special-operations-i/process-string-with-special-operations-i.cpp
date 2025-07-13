class Solution {
public:
    string processStr(string str) {
        vector<char> result;

        for (char ch : str) {
            if (islower(ch)) {
                result.push_back(ch);
            } 
            else if (ch == '*') {
                if (!result.empty()) result.pop_back();
            } 
            else if (ch == '#') {
                vector<char> temp = result;
                result.insert(result.end(), temp.begin(), temp.end());
            } 
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return string(result.begin(), result.end());
    }
};
