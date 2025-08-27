class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int gcdOfOddEvenSums(int n) {
        int odd_sum = 0;
        int even_sum = 0;

        for (int i = 2; i <= 2*n; i += 2) { 
            even_sum += i;
        }

        for (int i = 1; i <= 2*n; i += 2) { 
            odd_sum += i;
        }

        return gcd(odd_sum, even_sum);
    }
};
