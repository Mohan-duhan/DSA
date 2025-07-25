class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged;
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            merged.push_back(nums2[j]);
            j++;
        }
        int p = merged.size();
        if (p % 2 == 0) {
            return (merged[p / 2 - 1] + merged[p / 2]) /
                   2.0; 
        }
        else {
            return merged[p / 2];
        }
    }
};
