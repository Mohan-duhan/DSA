class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;

        unordered_map<int, int> arr;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            arr[nums[i]]++;
        }

        for (auto& it : arr) {
            if (it.second > k) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};
