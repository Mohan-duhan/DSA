class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= ans)
                ans += nums[i];
            else
                ans = nums[i];
        }
        return ans;
    }
};