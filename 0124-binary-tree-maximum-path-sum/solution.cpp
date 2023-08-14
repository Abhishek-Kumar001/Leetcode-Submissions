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
    int solve(TreeNode* root, int &maxi){
        if(root == NULL) return 0;

        int leftSum = solve(root->left, maxi);
        int rightSum = solve(root->right, maxi);

        
        leftSum = max(0, leftSum);  // vvvi b/c if leftSum i -ve we will not consider that path b/c 
        rightSum = max(0, rightSum);//  it is can,t be out path
        //root->val = max(0, root->val);

        maxi =  max(maxi, leftSum+rightSum+root->val);

        
        return max(leftSum , rightSum) + root->val;

    }
public:
    int maxPathSum(TreeNode* root) {
  /*  if(root->left == NULL  && root->right == NULL){
           return root->val;
        }   */
        
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};
