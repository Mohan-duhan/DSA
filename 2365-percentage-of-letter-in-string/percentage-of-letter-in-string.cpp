class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        double cnt = 0;

        for(int i = 0;i<n;i++){
            if(s[i] == letter)cnt++;
        }
        cnt = (cnt / n) * 100;
        return cnt;
    }
};