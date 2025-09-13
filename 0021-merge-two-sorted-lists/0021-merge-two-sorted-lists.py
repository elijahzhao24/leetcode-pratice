# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = None
        l1 = list1
        l2 = list2

        # initialize head with the smaller first element
        if l1:
            if l2:
                if l1.val <= l2.val:           
                    head = ListNode(l1.val)
                    l1 = l1.next
                else:
                    head = ListNode(l2.val)
                    l2 = l2.next
            else:
                head = ListNode(l1.val)
                l1 = l1.next
        else:
            if l2:
                head = ListNode(l2.val)
                l2 = l2.next

        cur = head

        while l1 or l2:
            if l1:
                if l2:
                    if l1.val <= l2.val:     
                        cur.next = ListNode(l1.val)
                        l1 = l1.next
                    else:
                        cur.next = ListNode(l2.val)
                        l2 = l2.next
                else:
                    cur.next = ListNode(l1.val)
                    l1 = l1.next
            else:
                if l2:
                    cur.next = ListNode(l2.val)
                    l2 = l2.next
            cur = cur.next
        return head
