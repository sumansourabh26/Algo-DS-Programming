# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self.loc = {item:i for i, item in enumerate(inorder)}
        return self.buildTreeH(inorder, postorder)
        
    
    def buildTreeH(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:

        if not inorder or not postorder:
            return None
        
        node = TreeNode(postorder[-1])
        index = self.loc[postorder[-1]]

        node.left = self.buildTree(
            inorder[0:index],
            postorder[0:index]
        )
        node.right = self.buildTree(
            inorder[index+1:],
            postorder[index:-1]
        )
        return node

        