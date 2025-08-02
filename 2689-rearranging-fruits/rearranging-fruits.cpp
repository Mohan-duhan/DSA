class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        unordered_map<int, int> freq;
        vector<int> store;
        int minEl = INT_MAX;

        for (int i = 0; i < basket1.size(); i++) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
            minEl = min({minEl, basket1[i], basket2[i]});
        }

        for (auto& [k, v] : freq) {
            if (v % 2 != 0)
                return -1;
            for (int i = 0; i < abs(v) / 2; i++) {
                store.push_back(k);
            }
        }
        // sort(store.begin(), store.end());
        nth_element(begin(store), begin(store) + store.size() / 2, end(store));
        
        long long cost = 0;
        for (int i = 0; i < store.size() / 2; i++) {
            cost += min((long long)2 * minEl, (long long)store[i]);
        }
        return cost;
    }
};