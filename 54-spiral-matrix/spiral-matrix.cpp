class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns
        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
            for (int j = scol; j <= ecol; j++)
                ans.push_back(matrix[srow][j]);
            srow++;

            for (int i = srow; i <= erow; i++)
                ans.push_back(matrix[i][ecol]);
            ecol--;

            if (srow <= erow) {
                for (int j = ecol; j >= scol; j--)
                    ans.push_back(matrix[erow][j]);
                erow--;
            }

            if (scol <= ecol) {
                for (int i = erow; i >= srow; i--)
                    ans.push_back(matrix[i][scol]);
                scol++;
            }
        }

        return ans;
    }
};
