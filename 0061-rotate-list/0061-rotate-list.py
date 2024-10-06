# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from collections import deque
from typing import Optional


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        
        if(head is None):
            return None

        left = head
        right = head

        i = 0
        while(i < k):
            if(right.next is None):
                k = k%(i+1)
                i = 0
                right = head
            else : 
                right = right.next
                i += 1

        while(right.next is not None):
            right = right.next
            left = left.next

        right.next = head
        head = left.next
        left.next = None
        return (head)