class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& arr) {
        int n = arr.size();
        int m = nums.size();

        vector<int> res(10001, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    res[arr[i]] = arr[j];
                    break;
                }
            }
        }

        vector<int> ans;
        for (int k : nums) {
            ans.push_back(res[k]);
        }
        return ans;
    }
};
