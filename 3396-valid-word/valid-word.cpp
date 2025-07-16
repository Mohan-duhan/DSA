class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        vector<bool> check;

        if (n < 3) {
            check.push_back(false);
        }

        bool hasVowel = false, hasConsonant = false;

        for (int i = 0; i < n; i++) {
            char ch = word[i];

            if (!isalnum(ch)) {
                check.push_back(false);
            } else {
                if (isalpha(ch)) {
                    char lower = tolower(ch);
                    if (lower == 'a' || lower == 'e' || lower == 'i' ||
                        lower == 'o' || lower == 'u') {
                        hasVowel = true;
                    } else {
                        hasConsonant = true;
                    }
                }
                check.push_back(true);
            }
        }

        if (!hasVowel || !hasConsonant) return false;

        for (int i = 0; i < check.size(); i++) {
            if (check[i] != true) return false;
        }

        return true;
    }
};
