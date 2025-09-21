class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();

        long long  org_sum = 0;
        long long exp_sum = n * (n + 1) / 2;

        long long org_SqSum = 0;
        long long exp_SqSum = n * (n + 1) * (2 * n + 1) / 6;

        for (int i = 0; i < n; i++) {
            org_sum += nums[i];
            org_SqSum += nums[i] * nums[i];
        }

        long long val1 = exp_sum - org_sum;
        long long val2 = exp_SqSum - org_SqSum;

        long long val3 = val2 / val1;

        int missing = (val3 + val1) / 2;
        int repeating = missing - val1;

        return {repeating, missing};
    }
};