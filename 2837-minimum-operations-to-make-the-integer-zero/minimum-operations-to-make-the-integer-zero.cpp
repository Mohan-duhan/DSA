class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 1; i <= 60; i++) {
            long long  res = num1 - 1LL * num2 * i;
            if (res < i) {
                return -1;
            }
            if (i >= __builtin_popcountll(res)) {
                return i;
            }
        }
        return -1;
    }
};