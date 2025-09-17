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
        int n = nums.size();
        stack<long long> s;
        s.push(nums[0]);

        for (int i = 1; i < n; i++) {
            long long cur = nums[i];
            while (!s.empty() && gcd(s.top(), cur) > 1) {
                cur = lcm(s.top(), cur);
                s.pop();
            }
            s.push(cur);
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
