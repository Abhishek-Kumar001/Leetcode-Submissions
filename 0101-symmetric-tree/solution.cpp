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
    bool helper(TreeNode* r1, TreeNode* r2){
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL || r2 == NULL) return false;

        if(r1->val != r2->val) return false;

        bool leftRight = helper(r1->left, r2->right);
        if(leftRight == false) return false;
        return helper(r1->right, r2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return helper(root->left, root->right);
    }
};
