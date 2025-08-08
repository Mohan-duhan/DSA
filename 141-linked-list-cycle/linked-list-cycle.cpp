class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if (head == NULL || head->next == NULL)
            return false;

        while (fast && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (fast == NULL || fast->next == NULL)
            return false;
        return true;
    }
};