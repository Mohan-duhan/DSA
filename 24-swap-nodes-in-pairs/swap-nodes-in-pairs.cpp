/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();

        for (int i = 1; i < n; i = i + 2) {
            swap(arr[i - 1], arr[i]);
        }

        temp = head;

        for (int i = 0; i < n; i++) {
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};