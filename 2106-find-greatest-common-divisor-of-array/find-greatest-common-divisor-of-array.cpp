class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        if (a == b)
            return a;

        if (a > b) {
            return gcd(a - b, b);
        } else {
            return gcd(a, b - a);
        }
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MIN;
        int b = INT_MAX;
        ;

        for (int i = 0; i < n; i++) {
            a = max(a, nums[i]);
            b = min(b, nums[i]);
        }

        return gcd(a, b);
    }
};