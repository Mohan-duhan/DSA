class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n);
        long long res = 0;

        for (int i = 0; i < n; i++) {
            int num = word[i] - '0';
            res = (res * 10 + num) % m; 
            ans[i] = (res == 0 ? 1 : 0);
        }
        return ans;
    }
};
