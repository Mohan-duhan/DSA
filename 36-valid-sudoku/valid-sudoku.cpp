class Solution {
public:

    bool solve(vector<vector<char>>& grid, int srow, int erow, int scol, int ecol) {
        set<char> st;
        for (int i = srow; i <= erow; i++) {
            for (int j = scol; j <= ecol; j++) {
                if (grid[i][j] == '.') continue;
                if (st.find(grid[i][j]) != st.end()) return false;
                st.insert(grid[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& grid) {
        // validate rows
        for (int i = 0; i < 9; i++) {
            set<char> st;
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == '.') continue;
                if (st.find(grid[i][j]) != st.end()) return false;
                st.insert(grid[i][j]);
            }
        }

        // validate columns
        for (int j = 0; j < 9; j++) {
            set<char> st;
            for (int i = 0; i < 9; i++) {
                if (grid[i][j] == '.') continue;
                if (st.find(grid[i][j]) != st.end()) return false;
                st.insert(grid[i][j]);
            }
        }

        // validate 3x3 subgrids
        for (int srow = 0; srow < 9; srow += 3) {
            int erow = srow + 2;
            for (int scol = 0; scol < 9; scol += 3) {
                int ecol = scol + 2;
                if (!solve(grid, srow, erow, scol, ecol)) return false;
            }
        }

        return true;
    }
};
