class Solution {
public:
    unordered_set<string> realWords;
    unordered_map<string, string> capitalMap;
    unordered_map<string, string> vowelMap;

    string toLower(string s) {
        for (char &ch : s) {
            ch = tolower(ch);
        }
        return s;
    }

    string toVowel(string s) {
        for (char &ch : s) {
            char lower = tolower(ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                ch = '*';
            } else {
                ch = lower;
            }
        }
        return s;
    }

    string check(string query) {
        if (realWords.count(query)) {
            return query;
        }

        string lowerQuery = toLower(query);
        if (capitalMap.count(lowerQuery)) {
            return capitalMap[lowerQuery];
        }

        string vowelQuery = toVowel(query);
        if (vowelMap.count(vowelQuery)) {
            return vowelMap[vowelQuery];
        }

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {

        realWords.clear();
        capitalMap.clear();
        vowelMap.clear();

        for (string &word : wordlist) {
            realWords.insert(word);

            string lowerWord = toLower(word);
            if (capitalMap.find(lowerWord) == capitalMap.end()) {
                capitalMap[lowerWord] = word;
            }

            string vowelWord = toVowel(word);
            if (vowelMap.find(vowelWord) == vowelMap.end()) {
                vowelMap[vowelWord] = word;
            }
        }

        vector<string> result;
        for (string query : queries) {
            result.push_back(check(query));
        }
        return result;
    }
};
