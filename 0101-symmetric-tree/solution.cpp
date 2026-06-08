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
    bool isHelperSymmetric(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;

        if(p->val != q->val) return false;

        bool isLeftSymmetric = isHelperSymmetric(p->left, q->right);;
        if(!isLeftSymmetric) return false;

        return isHelperSymmetric(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isHelperSymmetric(root->left, root->right);
    }
};
