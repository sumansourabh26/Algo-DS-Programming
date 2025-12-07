# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        
        self.inorder_pos = { inorder[i]:i for i in range(len(inorder))}
        return self.buildTree_h( preorder, inorder, (0, len(preorder)-1), (0, len(preorder)-1))

    def buildTree_h (
        self,
        preorder : List[int], 
        inorder : List[int], 
        po : Tuple[int, int],
        io : Tuple[int, int],
    ) -> Optional[TreeNode]: 
        if (po[0] > po[1]) or (io[0] > io[1]) : 
            return None
        
        root_val = preorder[po[0]]
        io_index = self.inorder_pos[root_val]

        
        left_node = self.buildTree_h(
            preorder, 
            inorder,
            (po[0] + 1, po[0]+1 + (io_index-1 - io[0])),
            (io[0], io_index-1),
        )

        right_node = self.buildTree_h(
            preorder,
            inorder, 
            (po[0]+1 + (io_index-1 - io[0])+1, po[1]),
            (io_index+1, io[1])
        )
        return TreeNode(root_val, left_node, right_node)

        