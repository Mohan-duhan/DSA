#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;

        for (int i = 0; pow(3, i) <= n; i++) {
            if (n == (int)pow(3, i))        
                return true;
        }
        return false;
    }
};
