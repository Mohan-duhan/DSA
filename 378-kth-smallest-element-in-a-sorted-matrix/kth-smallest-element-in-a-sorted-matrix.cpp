class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> flatten_array;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                flatten_array.push_back(matrix[i][j]);
            }
        }

        sort(flatten_array.begin(), flatten_array.end());
        return flatten_array[k - 1];
    }
};