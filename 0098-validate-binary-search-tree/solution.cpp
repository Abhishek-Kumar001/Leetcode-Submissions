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
    bool helper(TreeNode* root, long long min, long long max){
        if(root == NULL) return true;

        // base case 
        if(root->val >= max || root->val <= min) return false;
        bool isLeftTreeBST = helper(root->left, min, root->val);
        if(!isLeftTreeBST) return false;
        return helper(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
