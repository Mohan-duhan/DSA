class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int> arr;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        if (arr.size() < k)
            return head;

        int i = 0;
        while (i + k <= arr.size()) {  
            reverse(arr.begin() + i, arr.begin() + i + k);
            i += k;
        }

        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};
