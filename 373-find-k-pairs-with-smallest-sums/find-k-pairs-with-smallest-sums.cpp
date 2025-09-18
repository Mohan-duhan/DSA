class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p> pq; // max-heap
        vector<vector<int>> ans;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k) {
                    pq.push({sum, {i, j}});
                } else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                } else {
                    break;
                }
            }
        }

        while (!pq.empty()) {
            auto [sum, idx] = pq.top();
            pq.pop();
            ans.push_back({nums1[idx.first], nums2[idx.second]});
        }

        return ans;
    }
};
