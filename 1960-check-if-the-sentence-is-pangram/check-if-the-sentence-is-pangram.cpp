class Solution {
public:
    bool checkIfPangram(string str) {
        int n = str.length();
        if (n < 26)
            return false;
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[str[i] - 'a']++;
        }

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] < 1)
                return false;
        }
        return true;
    }
};