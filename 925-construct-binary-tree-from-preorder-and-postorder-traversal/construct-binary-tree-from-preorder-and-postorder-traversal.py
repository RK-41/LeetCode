# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # 23.02.25 potd
        idx = [0]
        return self.construct(preorder, postorder, idx, 0, len(preorder) - 1)

    def construct(self, pre, post, idx, low, high):
        if idx[0] >= len(pre) or low > high:
            return None

        root = TreeNode(pre[idx[0]])
        idx[0] += 1
        if low == high:
            return root

        i = low
        while i <= high and post[i] != pre[idx[0]]:
            i += 1

        if i <= high:
            root.left = self.construct(pre, post, idx, low, i)
            root.right = self.construct(pre, post, idx, i+1, high-1)

        return root