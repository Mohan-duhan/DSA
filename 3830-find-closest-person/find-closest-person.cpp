class Solution {
public:
    int findClosest(int x, int y, int z) {
        int res1 = abs(z - x);
        int res2 = abs(z - y);

        if (res1 < res2) {
            return 1;
        }
        else if (res1 > res2) {
            return 2;
        }
        else return 0;
    }
};