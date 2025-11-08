/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
int height(TreeNode* root, int diameter[]){

    if(root == NULL) return 0;

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    diameter[0] =  max( diameter[0], leftHeight+rightHeight );

    return max(leftHeight , rightHeight ) + 1;

}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter[1] = {0};
        height(root, diameter);
        return diameter[0];
    }
};
