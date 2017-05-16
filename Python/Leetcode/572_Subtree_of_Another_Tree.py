# -*- coding: utf-8 -*-

# Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s.
# A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

#   3
#  / \
# 5  4
#   / \
#  2  1
#
#
#   4
#  / \
# 2   1
#
# Return true

#   3
#  / \
#  4  5
# / \
# 2  1
# /
# 0
# Return false

def isSubtree(self, s, t):
    """
    :type s: TreeNode
    :type t: TreeNode
    :rtype: bool
    """

    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        # 递归遍历的方法
        # 譬如输入的是 0-9，从左到右排的树，输出为 ^0#^1#^3#^7#$$^8#$$^4#^9#$$$^2#^5#$$^6#$$
        # 在这里，convert 方法会先执行 if p else "$" 查看该结点是否为 None 再决定是否执行前面的部分，否则返回"$"
        def convert(p):
            return "^" + str(p.val) + "#" + convert(p.left) + convert(p.right) if p else "$"

        return convert(t) in convert(s)
