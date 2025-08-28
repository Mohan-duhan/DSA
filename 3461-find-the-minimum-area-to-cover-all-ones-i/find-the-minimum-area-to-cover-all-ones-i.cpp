class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int x_max = -1, y_max = -1;
        int x_min = INT_MAX, y_min = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    x_max = max(x_max, j);
                    x_min = min(x_min, j);

                    y_max = max(y_max, i);
                    y_min = min(y_min, i);
                }
            }
        }

        int l = x_max - x_min + 1;
        int b = y_max - y_min + 1;
        return l * b;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
