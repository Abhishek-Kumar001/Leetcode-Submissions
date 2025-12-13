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
    void bst(TreeNode* root, vector<int> &ans ){
        // base case 
        if(!root) return;
        
        bst(root->left, ans);
        ans.push_back(root->val);
        bst(root->right, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // as we know that the inorder traversal of bst is always in sorted order
        vector<int> ans;
        bst(root, ans);
        return ans[k-1];
    }
};
