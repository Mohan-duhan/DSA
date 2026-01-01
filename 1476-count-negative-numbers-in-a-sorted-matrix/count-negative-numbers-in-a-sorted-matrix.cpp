class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        int i = m - 1; // last row;
        int j = 0;     // first col;

        while (i >= 0 && j < n) {
            if (grid[i][j] < 0) {
                cnt += n - j;//agar wo particular column negative hai toh uske aage ke sare elements bhi -ve honge as matrix is sorted in decreasing order
                i--;
            } else {
                j++;
            }
        }
        return cnt;
    }
};