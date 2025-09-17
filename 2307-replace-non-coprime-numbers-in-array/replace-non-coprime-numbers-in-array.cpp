class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            long long cur = x;
            while (!ans.empty() && gcd(ans.back(), cur) > 1) {
                cur = lcm(ans.back(), cur);
                ans.pop_back();
            }
            ans.push_back((int)cur);
        }
        return ans;
    }
};
