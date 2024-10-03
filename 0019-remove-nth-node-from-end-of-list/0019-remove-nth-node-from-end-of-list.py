# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    "Remove Nth Node From End of List"
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        "Remove Nth Node From End of List"
        l = head
        r = head
        for _ in range(n):
            r = r.next
        
        if(r == None):
            return (l.next)

        while (r.next is not None):
            r = r.next
            l = l.next
        l.next = l.next.next
        return head