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
    void reorderList(ListNode* head) {

        if (!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        // find mid point

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow pointer contains mid point of bigger half
        // reverse that half

        ListNode* cur = slow->next;

        ListNode* temp = cur->next;
        cur->next = nullptr;
        slow->next = nullptr;
        while (temp) {
            ListNode* tempsnext = temp->next;
            temp->next = cur;
            cur = temp;
            temp = tempsnext;
        }

        // now alternate between connecting first and second half

        ListNode* secondHalf = cur;
        ListNode* firstHalf = head;

        while (secondHalf) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            firstHalf->next = secondHalf;
            secondHalf->next = temp1;
            firstHalf = temp1;
            secondHalf = temp2;
        }

    }
};
