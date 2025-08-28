class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int x_max = -1, y_max = -1;
        int x_min = m,  y_min = n;   

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (j < x_min) x_min = j;
                    if (j > x_max) x_max = j;
                    if (i < y_min) y_min = i;
                    if (i > y_max) y_max = i;
                }
            }
        }

        if (x_max == -1) return 0;

        int l = x_max - x_min + 1;
        int b = y_max - y_min + 1;
        return l * b;
    }
};
