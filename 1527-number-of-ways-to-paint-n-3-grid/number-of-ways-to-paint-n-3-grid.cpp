class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        //A = number of ways to paint a FULL ROW of type ABA
        //B = number of ways to paint a FULL ROW of type ABC
        long long A = 6, B = 6;//set for n = 1 initially

        for (int i = 2; i <= n; i++) {
            long long newA = (2 * A + 2 * B) % MOD;
            long long newB = (2 * A + 3 * B) % MOD;
            A = newA;
            B = newB;
        }

        return (A + B) % MOD;
    }
};