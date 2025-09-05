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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int> res;
        for (ListNode* node = head; node != nullptr; node = node->next) {
            res.push_back(node->val);
        }

        sort(res.begin(), res.end());

        ListNode* node = head;
        for (int val : res) {
            node->val = val;
            node = node->next;
        }

        return head;
    }
};