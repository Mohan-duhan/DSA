class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int, int>> pairSet;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    int a = min(nums[i], nums[j]);
                    int b = max(nums[i], nums[j]);
                    pairSet.insert({a, b});
                }
            }
        }
        return pairSet.size();
    }
};
