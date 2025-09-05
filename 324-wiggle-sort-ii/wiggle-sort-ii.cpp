class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;

        for (int num : nums)
            pq.push(num);

        int i = 1;
        while (i < n && pq.size()) {
            nums[i] = pq.top();
            pq.pop();
            i += 2;
        }

        int j = 0;
        while (j < n && pq.size()) {
            nums[j] = pq.top();
            pq.pop();
            j += 2;
        }
    }
};