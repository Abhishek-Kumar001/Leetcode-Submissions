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
    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int left =  helper(root->left);
        int right =  helper(root->right);
        
        if(left == -1 || right == -1) return -1;

        if(abs(left - right) > 1) return -1;
        return max(left , right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int result =  helper(root);
        if(result == -1) return false;
        return true;
    }
};



// class Solution {
//     int height(TreeNode* root){
//         if(root == NULL) return 0;

//         int left = 1 + height(root->left);
//         int right = 1 + height(root->right);
        
//         return max(left , right);
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL) return true;

//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);

//         if(!left || !right) return false;

//         int leftHeight = height(root->left);
//         int rightHeight = height(root->right);

//         if(abs(leftHeight - rightHeight) > 1) return false;
//         else return true;
//     }
// };
