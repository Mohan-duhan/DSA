class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<int> temp;
        for (auto &p : mp) {
            int freq = min(2, p.second);
            while (freq--) {
                temp.push_back(p.first);
            }
        }

        sort(temp.begin(), temp.end());
        nums = temp;

        return nums.size();
    }
};
