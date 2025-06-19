class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> vec(26, 0); 

        for (int i = 0; i < n; i++) {
            vec[s[i] - 'a']++;  
        }

        for (int i = 0; i < n; i++) {
            if (vec[s[i] - 'a'] == 1) {
                return i;      
            }
        }

        return -1;
    }
};
