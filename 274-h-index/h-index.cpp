class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int max_val = 0;
        int n = citations.size();

        for (int i = 0; i < n; i++) {
            int ans = n - i;
            max_val = max(max_val, min(citations[i], ans));
        }
        return max_val;
    }
};