# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def helper(root, balance) : 
    if not root: 
        return balance, None

    balance, lans = helper(root.left, balance)
    if lans : return None, lans

    balance -=1
    if(not balance): return None, root

    balance, rans = helper(root.right, balance)
    if rans : return None, rans

    return balance, None

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        balance, ans = helper (root, k)
        return ans.val
        
        