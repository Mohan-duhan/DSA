class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            set<int> rowSet;
            set<int> colSet;

            for (int j = 0; j < n; j++) {
                // Check row
                if (rowSet.find(matrix[i][j]) != rowSet.end()) 
                    return false;
                rowSet.insert(matrix[i][j]);

                // Check column
                if (colSet.find(matrix[j][i]) != colSet.end()) 
                    return false;
                colSet.insert(matrix[j][i]);
            }
        }

        return true;
    }
};
