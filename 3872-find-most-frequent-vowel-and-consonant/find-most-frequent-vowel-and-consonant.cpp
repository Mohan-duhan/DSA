class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxFreqSum(string s) {
        vector<int> freq(26);
        int maxVowel = 0;
        int maxConsonant = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
            if (isVowel(ch)) {
                maxVowel = max(maxVowel, freq[ch - 'a']);
            } else {
                maxConsonant = max(maxConsonant, freq[ch - 'a']);
            }
        }
        return maxVowel + maxConsonant;
    }
};