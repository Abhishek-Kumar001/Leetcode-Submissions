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
    void helper(vector<int> &ans, TreeNode* root, int i){
        if(root == NULL) return ;

        if(i == ans.size()) ans.push_back(root->val);

        if(root->right) helper(ans, root->right, i+1);
        if(root->left) helper(ans, root->left, i+1);
        return ;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(ans, root, 0);
        return ans;
    }
};
