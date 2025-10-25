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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curl1 = l1;
        ListNode* curl2 = l2;
        int lenl1 = 0;
        int lenl2 = 0;

        while (curl1) {
            ++lenl1;
            curl1 = curl1->next;
        }
        while (curl2) {
            ++lenl2;
            curl2 = curl2->next;
        }

        ListNode* returnHead;
        ListNode* lcur;
        ListNode* scur;
        int carry = 0;
        
        if (lenl1>=lenl2) {
            returnHead = l1;
            lcur = l1;
            scur = l2;
        } else {
            returnHead = l2;
            lcur = l2;
            scur = l1;
        }

        while (lcur) {
            int curtotal = carry;
            curtotal += lcur->val;
            if (scur) {
                curtotal += scur->val;
                scur = scur->next;
            }
            carry = curtotal/10;
            lcur->val = curtotal % 10;
            lcur= lcur->next;
        }

        if (carry > 0) {
            lcur = returnHead;
            while (lcur->next) {
                lcur = lcur->next;
            }
            lcur->next = new ListNode(carry);
        }


        return returnHead;
        
    }
};
