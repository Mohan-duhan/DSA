class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int max_val = -1;
            for (int j = i + 1; j < n; j++) {
                max_val = max(max_val, arr[j]);
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};