class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MIN;
        int b = INT_MAX;
        ;

        for (int i = 0; i < n; i++) {
            a = max(a, nums[i]);
            b = min(b, nums[i]);
        }

        int res = min(a, b);

        while (res > 0) {
            if (a % res == 0 && b % res == 0) {
                break;
            } else {
                res--;
            }
        }
        return res;
    }
};