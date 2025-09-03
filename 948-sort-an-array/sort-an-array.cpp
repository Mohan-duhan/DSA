class Solution {
public:
    void merge(vector<int> &arr, int left, int mid, int right) {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;

        vector<int> leftSubarr(arr.begin() + left, arr.begin() + left + leftSize);
        vector<int> rightSubarr(arr.begin() + mid + 1, arr.begin() + mid + 1 + rightSize);

        int i = 0, j = 0, k = left;

        while (i < leftSize && j < rightSize) {
            if (leftSubarr[i] <= rightSubarr[j]) {
                arr[k++] = leftSubarr[i++];
            } else {
                arr[k++] = rightSubarr[j++];
            }
        }

        while (i < leftSize) {
            arr[k++] = leftSubarr[i++];
        }

        while (j < rightSize) {
            arr[k++] = rightSubarr[j++];
        }
    }

    void mergeSort(vector<int> &arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
