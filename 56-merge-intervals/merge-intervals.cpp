class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

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