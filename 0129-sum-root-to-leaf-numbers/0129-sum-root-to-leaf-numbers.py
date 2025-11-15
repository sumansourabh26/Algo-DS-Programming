# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.final_sum = 0
    
    def sumNumbers(self, root: Optional[TreeNode], incoming_balance = 0) -> int:
        this_node_balance = incoming_balance*10 + root.val

        if not (root.right or root.left ):
            self.final_sum += this_node_balance
            return self.final_sum
        if root.right : 
            self.sumNumbers(root.right, this_node_balance)
        if root.left : 
            self.sumNumbers(root.left, this_node_balance)
        return self.final_sum 
        
        