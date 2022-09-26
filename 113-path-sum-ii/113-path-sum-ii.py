# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        def findPath(root, targetSum, path):
            if root == None:
                return None
            targetSum -= root.val
            path.append(root.val)
            if root.left == None and root.right == None:
                if targetSum == 0:
                    ans.append(path.copy())
            else:
                findPath(root.left, targetSum, path)
                findPath(root.right, targetSum, path)
            path.pop()
        ans = []
        findPath(root, targetSum, [])
        return ans;