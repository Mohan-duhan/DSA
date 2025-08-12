class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        if (k < 0) return 0;  
        int res = 0;

        for (auto num : nums) {
            mp[num]++;
        }

        for (auto& [n, count] : mp) {
            if (k == 0) {
                if (count >= 2) res++;
            } else {
                if (mp.find(n + k) != mp.end()) res++;
            }
        }
        return res;
    }
};
