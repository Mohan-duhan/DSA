class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxFreqSum(string s) {
        vector<int> freqVowel(26);
        vector<int> freqConsonant(26);
        int maxVowel = 0;
        int maxConsonant = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isVowel(ch)) {
                freqVowel[ch - 'a']++;
                maxVowel = max(maxVowel, freqVowel[ch - 'a']);
            } else {
                freqConsonant[ch - 'a']++;
                maxConsonant = max(maxConsonant, freqConsonant[ch - 'a']);
            }
        }
        return maxVowel + maxConsonant;
    }
};