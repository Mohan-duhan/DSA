class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();

        for (int i = 0; i <= n - 3; i++) {
            string res = num.substr(i, 3);
            if (res == "999" || res == "888" || res == "777" ||
                res == "666" || res == "555" || res == "444" ||
                res == "333" || res == "222" || res == "111" || res == "000") {
                if (res > ans) ans = res;
            }
        }
        return ans;
    }
};
