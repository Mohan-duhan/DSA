class Solution {
public:
    int count = 0;
    void countPairs(vector<int>& arr, int left, int mid, int right) {
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;

        vector<int> leftSubarr(arr.begin() + left,
                               arr.begin() + left + leftSize);
        vector<int> rightSubarr(arr.begin() + mid + 1,
                                arr.begin() + mid + 1 + rightSize);

        int i = 0, j = 0, k = left;

        while (i < leftSize && j < rightSize) {
            if (leftSubarr[i] <= rightSubarr[j]) {
                arr[k++] = leftSubarr[i++];
            } else {
                arr[k++] = rightSubarr[j++];
            }
        }

        while (i < leftSize) arr[k++] = leftSubarr[i++];
        while (j < rightSize) arr[k++] = rightSubarr[j++];
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            countPairs(arr, left, mid, right);
            merge(arr, left, mid, right);
        }
    }

    int reversePairs(vector<int>& arr) {
        count = 0;
        mergeSort(arr, 0, arr.size() - 1);
        return count;
    }
};
