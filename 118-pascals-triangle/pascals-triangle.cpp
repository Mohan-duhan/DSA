class Solution {
public:
    vector<int> generateRows(int numRows) {
        long long ans = 1;
        vector<int> result;
        result.push_back(1);
        for (int i = 1; i < numRows; i++) {
            ans = ans * (numRows - i);
            ans = ans / (i);
            result.push_back(ans);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows;i++) {
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};