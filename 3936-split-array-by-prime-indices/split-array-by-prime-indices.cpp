class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {
        vector<int> A;
        vector<int> B;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (isPrime(i)) {
                A.push_back(nums[i]);
            } else {
                B.push_back(nums[i]);
            }
        }

        long long sum_A = 0, sum_B = 0;

        for (int x : A)
            sum_A += x;
        for (int x : B)
            sum_B += x;

        long long diff = abs(sum_A - sum_B);
        return min(diff, 100000000000000LL);
    }
};
