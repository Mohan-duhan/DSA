class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();

        int i = 0, j = 0, sum = 0, res = 0;

        while (j < n) {
            if (!seen.count(nums[j])) {
                sum += nums[j];
                res = max(res, sum);
                seen.insert(nums[j]);
                j++;
            } else {
                while (i < n && seen.count(nums[j])) {
                    sum -= nums[i];
                    seen.erase(nums[i]);
                    i++;
                }
            }
        }
        return res;
    }
};