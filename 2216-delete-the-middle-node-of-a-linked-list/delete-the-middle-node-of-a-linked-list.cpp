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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        int k = 0;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            k++;
            fast = fast->next->next;
        }

        ListNode* curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }

        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;

        return head;
    }
};
