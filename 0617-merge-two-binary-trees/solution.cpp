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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //base case 
        if(root1 == NULL  && root2 == NULL) return NULL;

        int sum = 0;
        if(root1 != NULL) sum+=root1->val;
        if(root2 != NULL) sum+=root2->val;

        TreeNode* root = new TreeNode(sum);

        // make left call
        if(root1 && root2){
            root->left = mergeTrees(root1->left , root2->left);
        }else if(root1){
            root->left = mergeTrees(root1->left , root2);
        }else{
            root->left = mergeTrees(root1 , root2->left);
        }

        //make right calls
        if(root1 && root2){
            root->right = mergeTrees(root1->right, root2->right);
        }else if(root1){
            root->right = mergeTrees(root1->right, root2);
        }else{
            root->right = mergeTrees(root1, root2->right);
        }

        //return root
        return root;
    }
};
