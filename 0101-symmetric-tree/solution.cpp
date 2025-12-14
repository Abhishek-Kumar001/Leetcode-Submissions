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
    bool helper(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL) return false;
        if(t2 == NULL) return false;

        if(t1->val != t2->val) return false;

        bool ans = helper(t1->left, t2->right);
        if(ans == false) return false;
        bool ans2 = helper(t1->right, t2->left);
        if(ans2 == false) return false;

        return true;

    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};
