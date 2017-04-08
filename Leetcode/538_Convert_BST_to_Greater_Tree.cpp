//
// Created by edvard on 05/04/2017.
//
// Given a Binary Search Tree (BST), convert it to a Greater Tree such that
// every key of the original BST is changed to the original key plus sum of
// all keys greater than the original key in BST.

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

int cur_sum = 0;

void travel(TreeNode * root) {
    if(!root) return ;

    if(root->right)
        travel(root->right);

    root->val = (cur_sum += root->val);
    if(root->left)
        travel(root->left);
}

TreeNode* convertBST(TreeNode* root) {
    travel(root);
    return root;
}

int main(void) {

}

