class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);
        stack<int>s;

        for (int i = 0; i < n; i++) {
            while(!s.empty() && arr[i] > arr[s.top()]){
                int idx = s.top();
                s.pop();
                res[idx] = i-idx;
            }
            s.push(i);
        }
        return res;
    }
};
