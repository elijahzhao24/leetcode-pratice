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

        if (!head || !head->next) {
            return head;
        }

        ListNode* left = head;
        ListNode* right = getmid(head);

        ListNode* temp = right->next;
        right->next = nullptr;
        right = temp;

        left = sortList(left);
        right = sortList(right);

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                tail = tail->next;
                left = left->next;
                tail->next = nullptr;
            } else {
                tail->next = right;
                tail = tail->next;
                right = right->next;
                tail->next = nullptr;
            }
        }

        if (left) {
            tail->next = left;
        } else {
            tail->next = right;
        }

        return dummy.next;
    }


    ListNode* getmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

};