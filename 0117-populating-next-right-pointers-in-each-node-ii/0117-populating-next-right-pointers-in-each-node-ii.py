"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from collections import deque
class Solution:
    def __init__(self):
        self.stack = deque()
    
    def connect(self, root: 'Node') -> 'Node':
        if(not root):
            return
        if(len(self.stack)):
            left_n = self.stack.pop()
            left_n.next = root
        if(root.left):
            self.connect(root.left)
        if(root.right):
            self.connect(root.right)
        self.stack.append(root)
        return root

        