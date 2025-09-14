class Solution {
public:
    static bool compare(const pair<char,int>& a, const pair<char,int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> res(freq.begin(), freq.end());

        sort(res.begin(), res.end(), compare);

        string str = "";
        for (int i = 0; i < res.size(); i++) {
            // ye str me res.second times res.first ko add karega
            str.append(res[i].second, res[i].first);
        }
        return str;
    }
};
