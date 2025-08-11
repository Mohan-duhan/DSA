class Solution {
public:
    bool powerofTwo(int num) {
        return (num > 0) && ((num & (num - 1)) == 0);
    }
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(str.begin(), str.end());
        do {
            if (str[0] == '0') continue;
            if (powerofTwo(stoi(str))) return true;
        } while (next_permutation(str.begin(), str.end()));
        return false;
    }
};
