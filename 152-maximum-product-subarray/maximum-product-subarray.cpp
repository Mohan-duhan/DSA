class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currPro = 1;
        int maxPro = INT_MIN;

        for (int i = 0; i < n; i++) {
            currPro *= nums[i];
            maxPro = max(maxPro, currPro);
            if (currPro == 0) {
                currPro = 1;
            }
        }

        currPro = 1;
        for (int i = n - 1; i >= 0; i--) {
            currPro *= nums[i];
            maxPro = max(maxPro, currPro);
            if (currPro == 0) {
                currPro = 1;
            }
        }
        return maxPro;
    }
};