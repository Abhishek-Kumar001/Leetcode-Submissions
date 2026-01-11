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
    void helper(TreeNode* root, vector<string> &ans, string temp) {
        if (root == nullptr) return;

        // Add current node value
        temp += to_string(root->val);

        // If leaf node, store path
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(temp);
            return;
        }

        // Continue path
        temp += "->";

        helper(root->left, ans, temp);
        helper(root->right, ans, temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) return ans;

        helper(root, ans, "");
        return ans;
    }
};
