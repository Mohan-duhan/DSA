class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int result = 0;
        int maxNegativeValue = INT_MIN;

        for (int num : nums) {
            if (num > 0) {
                seen.insert(num);
            } else {
                maxNegativeValue = max(maxNegativeValue, num);
            }
        }

        for (int num : seen) {
            result += num;
        }

        return result == 0 ? maxNegativeValue : result;
    }
};
