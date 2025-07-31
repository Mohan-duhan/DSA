class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum1 = 0;
        int pro1 = 1;
        int res = 0;

        while (num > 0) {
            int last_digit = num % 10;
            sum1 += last_digit;
            pro1 *= last_digit;
            num = num / 10;
        }
        res = sum1 + pro1;
        if (n % res == 0)
            return true;
        else
            return false;
    }
};