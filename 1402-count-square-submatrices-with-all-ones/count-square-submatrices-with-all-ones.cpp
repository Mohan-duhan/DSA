class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, int m, int n,
              vector<vector<int>>& dp) {
        if (i >= m || j >= n)
            return 0;

        if (matrix[i][j] == 0)
            return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(matrix, i, j + 1, m, n, dp);
        int below = solve(matrix, i + 1, j, m, n, dp);
        int diag = solve(matrix, i + 1, j + 1, m, n, dp);

        return dp[i][j] = 1 + min({right, below, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    result += solve(matrix, i, j, m, n, dp);
                }
            }
        }
        return result;
    }
};