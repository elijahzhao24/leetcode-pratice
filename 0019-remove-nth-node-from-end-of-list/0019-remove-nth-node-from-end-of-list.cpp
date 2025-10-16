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
        int length = 0;
        
        ListNode* cur = head;
        while (cur) {
            length++;
            cur = cur->next;
        }
        int target = length - n-1;

        if (length <= 1) {
            return nullptr;
        }
        if (target == -1) {
            return head->next;
        }


        cur = head;

        while (target > 0) {
            cur = cur->next;
            --target;
        }
        cur->next = cur->next->next;
        return head;
    }
};
