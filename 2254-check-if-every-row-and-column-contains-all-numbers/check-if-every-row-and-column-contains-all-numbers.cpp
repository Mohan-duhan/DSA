class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){
            vector<bool> row(n + 1, 0);
            vector<bool> col(n + 1, 0);

            for(int j=0; j<n; j++){
                int r = matrix[i][j];
                int c = matrix[j][i];

                if(row[r] || col[c]) return false;
                
                row[r] = true;
                col[c] = true;
            }
        }

        return true;
    }
};