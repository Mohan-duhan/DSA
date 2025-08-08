class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (fruits[i] <= baskets[j] && !visited[j]) {
                    visited[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                count++;
            }
        }
        return count;
    }
};