# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.rv : List[int] =[None]*101

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.rightSideViewH(root, 0)
        length = self.rv.index(None)
        return (self.rv[0:length])

    def rightSideViewH(self, root: Optional[TreeNode], level : int):
        if(not root): return
        
        self.rv[level] = root.val
        if(root.left):
            self.rightSideViewH(root.left, level+1)
        if(root.right):
            self.rightSideViewH(root.right, level+1)
        



        