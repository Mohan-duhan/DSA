class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        vector<int> arr;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int i = left - 1;      
        reverse(arr.begin() + i, arr.begin() + right);

        temp = head;
        for (int k = 0; k < arr.size(); k++) {
            temp->val = arr[k];
            temp = temp->next;
        }

        return head;
    }
};
