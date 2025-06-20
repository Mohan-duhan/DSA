class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;

        long long start = 1;
        long long end = num / 2;

        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long res = mid * mid;

            if (res == num) return true;
            else if (res < num) start = mid + 1;
            else end = mid - 1;
        }

        return false;
    }
};
