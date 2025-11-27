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
    TreeNode* successor(TreeNode* root){
        if(root == NULL) return root;
        if(root->left == NULL) return root;  // vvi not need to check for right 
        // if(root->left == NULL && root->right) return root;
        return successor(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            if(root->left == NULL && root->right == NULL) return NULL;
            else if(root->left == NULL) return root->right;
            else if(root->right == NULL) return root->left;
            else{
                TreeNode* rightLeast = successor(root->right);
                root->val = rightLeast->val;
                root->right = deleteNode(root->right, rightLeast->val);  // vvi
            }
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else root->left = deleteNode(root->left, key);
        
        return root;  /// vvi 
    }
};
