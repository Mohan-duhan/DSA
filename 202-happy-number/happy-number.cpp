class Solution {
public:
    int sqSumofDigits(int n) {
        int ans = 0;
        while (n > 0) {
            int last_digit = n % 10;
            ans += last_digit * last_digit;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while (st.find(n) == st.end()) {
            st.insert(n);
            n = sqSumofDigits(n);
            if (n == 1)
                return true;
        }
        return false;
    }
};