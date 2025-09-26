class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int fullSum = 0, partialSum = 0;
        for (int num : nums) {
            fullSum += num;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (partialSum * 2 == fullSum - nums[i]) {
                return i;
            }
            partialSum += nums[i];
        }
        return -1;
    }
};