/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(next) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string str = "";

        while (head != NULL) {
            str.push_back(head->val + '0'); 
            head = head->next;
        }

        int dec_val = stoi(str, nullptr, 2);
        return dec_val;
    }
};
