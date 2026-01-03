class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        //A_two = number of ways to paint a FULL ROW of type ABA
        //B_three = number of ways to paint a FULL ROW of type ABC
        long long A_two = 6, B_three = 6;//set for n = 1 initially

        for (int i = 2; i <= n; i++) {
            long long newB = (2 * A_two + 2 * B_three) % MOD;//3 se 2 me jaine ke or 3 se 2 me naine ke (all t)
            long long newA = (3 * A_two + 2 * B_three) % MOD;//2 ae 2 me jaine ke or 2 se 3 me jaine ke 
            A_two = newA;
            B_three = newB;
        }

        return (B_three + A_two) % MOD;
    }
};