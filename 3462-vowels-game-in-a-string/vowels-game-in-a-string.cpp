class Solution {
public:
    bool doesAliceWin(string s) {
     unordered_set<char> vowels = {'a','e','i','o','u'};
        for(int i=0;i<s.size();i++)
        {
            if(vowels.count(s[i]))
            return true;
        }
        return false;
    }
};