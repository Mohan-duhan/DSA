class Solution {
public:
    vector<string> getToken(string version) {
        stringstream ss(version);
        string word;
        vector<string> ans;

        while (getline(ss, word, '.')) {
            ans.push_back(word);
        }
        return ans;
    }

    int compareVersion(string version1, string version2) {
        vector<string> vec1 = getToken(version1);
        vector<string> vec2 = getToken(version2);

        int n = vec1.size();
        int m = vec2.size();
        int i = 0;

        while (i < n || i < m) {
            int a = i < n ? stoi(vec1[i]) : 0;
            int b = i < m ? stoi(vec2[i]) : 0;

            if (a < b)
                return -1;
            else if (a > b)
                return 1;
            else
                i++;
        }
        return 0;
    }
};
