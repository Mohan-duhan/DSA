class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        next_permutation(str.begin(), str.end());
        long res = stol(str); //string to long 

        if (res > INT_MAX || res <= n)
            return -1;
        else
            return res;
    }
};