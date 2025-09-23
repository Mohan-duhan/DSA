class Solution {
public:
    vector<int> getToken(string version) {
        stringstream ss(version);
        string num;
        vector<int> ans;

        while (getline(ss, num, '.')) {
            ans.push_back(stoi(num)); 
        }
        return ans;
    }

    int compareVersion(string version1, string version2) {
        vector<int> vec1 = getToken(version1);
        vector<int> vec2 = getToken(version2);

        int n = vec1.size();
        int m = vec2.size();
        int i = 0;

        while (i < n || i < m) {
            int a = i < n ? vec1[i] : 0;
            int b = i < m ? vec2[i] : 0;

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
