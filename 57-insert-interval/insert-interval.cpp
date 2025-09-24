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
            if(!ans.empty() && intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};