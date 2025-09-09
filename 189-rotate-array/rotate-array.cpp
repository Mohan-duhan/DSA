class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;
        int m = n - k;

        reverse(arr.begin() + m, arr.end());     
        reverse(arr.begin(), arr.begin() + m);
        reverse(arr.begin(), arr.end());  
    }
};
