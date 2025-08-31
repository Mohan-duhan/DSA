class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //validate rows
        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = 0; j < m; j++) {
                if (st.find(matrix[i][j]) != st.end()) {
                    return false;
                }
                st.insert(matrix[i][j]);
            }
        }

        //validate columns
        for (int j = 0; j < n; j++) {
            set<int> st;
            for (int i = 0; i < m; i++) {
                if (st.find(matrix[i][j]) != st.end()) {
                    return false;
                }
                st.insert(matrix[i][j]);
            }
        }

        return true;
    }
};