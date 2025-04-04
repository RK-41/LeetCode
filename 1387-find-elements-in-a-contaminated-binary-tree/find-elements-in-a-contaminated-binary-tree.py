# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:
    # 21.02.25 POTD
    def __init__(self, root: Optional[TreeNode]):
        self.st = set()
        self.recover(root, 0)

    def find(self, target: int) -> bool:
        return target in self.st
    
    def recover(self, node, val):
        if not node:    return

        node.data = val
        self.st.add(val)
        self.recover(node.left, val * 2 + 1)
        self.recover(node.right, val * 2 + 2)

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)