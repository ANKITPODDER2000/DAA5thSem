# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        lh = self.height(root.left)
        rh = self.height(root.right)
        
        ld = self.diameterOfBinaryTree(root.left)
        rd = self.diameterOfBinaryTree(root.right)
        
        return max(lh+rh,ld,rd)
        
    def height(self,node):
        if node is None :
            return 0
        return 1 + max(self.height(node.left),self.height(node.right))