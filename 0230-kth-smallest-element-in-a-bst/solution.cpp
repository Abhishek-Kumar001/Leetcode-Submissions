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
    void inorderTraversal(TreeNode* root, vector<int>& arr){
        // base case 
        if(root == NULL) return;

        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // as we know the inorder traversal of BST is always in sorted order
        vector<int> arr;
        inorderTraversal(root, arr);

        return arr[k-1];
    }
};
