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

        if (nums.size() >= 1) B.push_back(nums[0]);
        if (nums.size() >= 2) B.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (isPrime(i)) {
                A.push_back(nums[i]);
            } else {
                B.push_back(nums[i]);
            }
        }

        long long sum_A = 0, sum_B = 0;

        for (int num : A) sum_A += num;
        for (int num : B) sum_B += num;

        return abs(sum_A - sum_B);
    }
};
