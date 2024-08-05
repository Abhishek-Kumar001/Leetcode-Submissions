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
    bool helper(TreeNode* root, int targetSum, int sum){
              // this base case does't correct a/c our  question
              // eg: 1=>2, targetSum=1; our o/p:-true but correct o/p:-false
              // eg: 1->2->3->4, tarSum=3; our o/p:-true but correct o/p:-false
        // if(root == NULL ){
        //     return sum == targetSum;
        // }


        // correct base case   
        if(root == NULL) return false;     
        if(root->left == NULL && root->right == NULL){
            return sum+root->val == targetSum;
        }
        
        

        bool left = helper(root->left, targetSum, sum + root->val);
        if(left) return true;
        bool right = helper(root->right, targetSum, sum + root->val);

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // corner case 1
        if(root == NULL) return false;
       
        int sum =0;
        return helper(root, targetSum, sum );
        
    }
};
