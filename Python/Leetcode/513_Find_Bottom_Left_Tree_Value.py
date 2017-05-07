# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # left = []
        # row = [root]
        # while any(row):
        #     row = [kid for node in row for kid in (node.left, node.right) if kid]
        #     if row:
        #         left.append(row[0])
        # return left[-1]

        queue = [root]
        for node in queue:
            queue += filter(None, (node.right, node.left))
        return node.val