class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());

        int n = nums.size();
        int mid = (n + 1) / 2;
        int i = mid - 1;
        int j = n - 1;

        for (int k = 0; k < n; k++) {
            if (k % 2 == 0) {
                nums[k] = arr[i--];
            } else {
                nums[k] = arr[j--];
            }
        }
    }
};