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
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int n = arr.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            ListNode* temp = arr[i];
            while (temp != NULL) {
                res.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(res.begin(), res.end());

        if (res.empty()) return nullptr; 

        ListNode* head = new ListNode(res[0]);
        ListNode* dummy = head;

        for (int i = 1; i < res.size(); i++) {
            dummy->next = new ListNode(res[i]);
            dummy = dummy->next;
        }
        return head;
    }
};
