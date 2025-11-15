# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self.loc = {item:i for i, item in enumerate(inorder)}
        return self.buildTreeH(inorder, postorder, (0, len(inorder)-1), (0, len(inorder)-1))
        
    
    def buildTreeH(self, inorder: List[int], postorder: List[int], ino, po) -> Optional[TreeNode]:

        if (ino[0]>ino[1]) or (po[0]>po[1]):
            return None
        
        node = TreeNode(postorder[po[1]])
        index = self.loc[postorder[po[1]]]

        node.left = self.buildTreeH(
            inorder,
            postorder,
            (ino[0],index-1),
            (po[0], po[0] + index-ino[0]-1)
        )
        node.right = self.buildTreeH(
            inorder,
            postorder,
            (index+1,ino[1]),
            (po[0] + index-ino[0], po[1]-1)
        )
        return node

        