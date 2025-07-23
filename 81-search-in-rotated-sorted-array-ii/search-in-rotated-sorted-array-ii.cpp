class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int d = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                d = i;
                break;
            }
        }

        reverse(nums.begin(), nums.begin() + d);
        reverse(nums.begin() + d, nums.end());
        reverse(nums.begin(), nums.end());

        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) return true;
            else if (nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }

        return false;
    }
};
