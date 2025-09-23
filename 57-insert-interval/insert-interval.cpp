class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        if (intervals.empty()) {
            return {};
        }

        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};