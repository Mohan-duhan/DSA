class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(1001, 0); 

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        for (int count : freq) {
            if (isPrime(count)) return true;
        }
        return false;
    }
};
