class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode* curr = head;

        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int n = arr.size();
        swap(arr[k-1], arr[n-k]);

        curr = head;
        for (int i = 0; i < n; i++) {
            curr->val = arr[i];
            curr = curr->next;
        }

        return head;
    }
};
