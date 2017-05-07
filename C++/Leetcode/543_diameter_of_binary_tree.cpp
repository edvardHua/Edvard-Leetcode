//
// Created by edvard on 03/04/2017.
//
// Given a binary tree, you need to compute the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.
//

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

int maxDiameter = 0;

int dfs(TreeNode* root){
    if(root == NULL)
        return 0;

    int leftDepth = 0, rightDepth = 0;

    if(root->left != NULL)
        leftDepth = dfs(root->left);
    if(root->right != NULL)
        leftDepth = dfs(root-right);

    if((leftDepth + rightDepth) > maxDiameter)
        maxDiameter = leftDepth + rightDepth;

    return max(leftDepth + 1, rightDepth + 1);
}

int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return maxDiameter;
}


int main(void){

}
