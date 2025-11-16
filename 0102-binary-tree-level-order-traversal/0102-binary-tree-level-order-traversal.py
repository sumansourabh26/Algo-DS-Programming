# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.level_order = [None]*2001
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.levelOrderH(root,0)
        ending = self.level_order.index(None)
        return self.level_order[:ending]

    def levelOrderH(self, root: Optional[TreeNode], level) -> List[List[int]]:
        if(not root): return
        
        if(not self.level_order[level]):
            self.level_order[level] = []
        self.level_order[level].append(root.val)

        if(root.left) : self.levelOrderH(root.left,level+1)
        if(root.right) : self.levelOrderH(root.right,level+1)


        