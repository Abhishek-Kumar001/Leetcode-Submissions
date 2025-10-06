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
    pair<bool, int> helper(TreeNode* root){
        // base case 
        if(root == NULL) return {false, 0};
        if(root->left == NULL and root->right == NULL) return {true, 1};

        pair<bool, int> left =  helper(root->left);
        pair<bool, int> right =  helper(root->right);

        if(left.first && right.first) return {true,  min(left.second, right.second) + 1};
        if(!left.first) return {right.first, right.second+1};
        return {left.first, left.second+1};
    }
public:
    int minDepth(TreeNode* root) {

        pair<bool, int> result =  helper(root);
        return result.second;
    }
};
