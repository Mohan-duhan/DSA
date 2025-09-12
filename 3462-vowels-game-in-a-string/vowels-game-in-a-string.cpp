class Solution {
public:
    bool doesAliceWin(string s) {
    string str="aeiou";
        for(int i=0;i<s.size();i++)
        {
            if(str.find(s[i])!=string::npos)
            return true;
        }
        return false;
    }
};