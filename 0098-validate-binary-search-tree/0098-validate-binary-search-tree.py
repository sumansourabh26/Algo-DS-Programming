# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def helper(node): #return max, min, isValid
    mx = mn = node.val
    is_valid = True
    if node.left:
        lmx, lmn, is_valid = helper(node.left)
        if not is_valid : return (None, None, False)
        if(lmx >= node.val) : return (None, None, False)
        mn = lmn

    if node.right:
        rmx, rmn, is_valid = helper(node.right)
        if not is_valid : return (None, None, False)
        if(rmn <= node.val) : return (None, None, False)
        mx = rmx

    return(
        mx,
        mn,
        True
    )


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        (_,_, is_valid) = helper(root)
        return is_valid
        