# -*- coding: utf-8 -*-

from math import log
from math import ceil

class Node(object):
    def __init__(self, elem = -1, lchild = None, rchild = None):
        self.elem = elem
        self.lchild = lchild
        self.rchild = rchild

class Tree(object):
    def __init__(self):
        self.root = Node()
        self.myQueue = []

    def add(self, elem):
        """为树添加节点"""
        node = Node(elem)
        if self.root.elem == -1:  # 如果树是空的，则对根节点赋值
            self.root = node
            self.myQueue.append(self.root)
        else:
            treeNode = self.myQueue[0]  # 此结点的子树还没有左子树。
            if treeNode.lchild == None:
                treeNode.lchild = node
                self.myQueue.append(treeNode.lchild)
            else:
                treeNode.rchild = node
                self.myQueue.append(treeNode.rchild)
                self.myQueue.pop(0)  # 如果该结点存在左右子树，将此结点丢弃。

    def level_queue(self, root):
        """利用队列实现树的层次遍历"""
        if root == None:
            return
        myQueue = []
        elems = []
        node = root
        myQueue.append(node)
        while myQueue:
            node = myQueue.pop(0)
            elems.append(node.elem)
            if node.lchild != None:
                myQueue.append(node.lchild)
            if node.rchild != None:
                myQueue.append(node.rchild)

        return elems

    def convert(self, p):
        return "^" + str(p.elem) + "#" + self.convert(p.lchild) + self.convert(p.rchild) if p else "$"

if __name__ == '__main__':
    """主函数"""
    elems = range(10)
    tree = Tree()
    for elem in elems:
        tree.add(elem)

    print tree.convert(tree.root)

    # elems = tree.level_queue(tree.root)
    #
    # # 需要考虑当val为 None 或者 null 的状态
    # levelMax = [elems[0]]
    # for i in range(1, int(ceil(log(len(elems), 2)))):
    #     levelMax.append(max(elems[2**(i)-1:2**(i+1)-1]))
    #
    # print levelMax


