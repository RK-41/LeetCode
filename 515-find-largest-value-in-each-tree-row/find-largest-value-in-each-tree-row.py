# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        # 25.12.24 POTD
        if not root:
            return []

        ans, q = [], []
        q.append(root)

        while q:
            sz = len(q)
            mx = q[0].val

            while sz:
                sz -= 1
                nd = q.pop(0)
                mx = max(mx, nd.val)

                if nd.left:
                    q.append(nd.left)
                if nd.right:
                    q.append(nd.right)
            
            ans.append(mx)

        return ans