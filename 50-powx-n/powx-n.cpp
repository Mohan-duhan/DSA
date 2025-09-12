class Solution {
public:
    double doublePow(double x , long n){
        if(n == 0) return 1;
        if(n < 0) return 1.0 / doublePow(x, -n);

        double half = doublePow(x, n/2);

        if(n % 2 == 0) return half * half;
        else return x * half * half;
    }

    double myPow(double x, int n) {
        return doublePow(x, (long)n);
    }
};
