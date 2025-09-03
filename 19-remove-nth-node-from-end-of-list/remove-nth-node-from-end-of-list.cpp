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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int size = 0;

        while (curr != NULL) {
            size++;
            curr = curr->next;
        }
        
        int k = size - n;
        if (k == 0) { // agar head he delete karna pade tab
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        curr = head;

        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }
        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;

        return head;
    }
};