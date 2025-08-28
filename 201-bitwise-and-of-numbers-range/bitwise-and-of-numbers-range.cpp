class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        while (left < right) {
            left >>= 1;//right shift by 1  bit
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};