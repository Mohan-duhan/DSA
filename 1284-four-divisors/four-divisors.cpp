class Solution { 
public: 
    vector<pair<int, int>> pairs; 

    void solve(int x) { 
        int sum = 1 + x; 
        int cnt = 2; // 1 and x

        for (int i = 2; i * i <= x; i++) { 
            if (x % i == 0) { 
                int d1 = i; 
                int d2 = x / i; 

                if (d1 == d2) { 
                    cnt++; 
                    sum += d1; 
                } else { 
                    cnt += 2; 
                    sum += d1 + d2; 
                } 
            } 
        } 

        if (cnt == 4) { 
            pairs.push_back({sum, cnt}); 
        } 
    } 

    int sumFourDivisors(vector<int>& nums) { 
        int ans = 0; 

        for (int x : nums) { 
            solve(x); 
        } 

        for (auto &p : pairs) { 
            ans += p.first; 
        } 

        return ans; 
    } 
};
