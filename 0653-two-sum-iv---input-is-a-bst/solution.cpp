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
private:
   void inorderTraversal(TreeNode* root, vector<int> &inorderArr){
      // base case
      if(root == NULL) return ;

      inorderTraversal(root->left, inorderArr);
      inorderArr.push_back(root->val);
      inorderTraversal(root->right, inorderArr);
   }
public:
    bool findTarget(TreeNode* root, int k) {
        // we know that the inorder of bst in sorted order
        // so 1st we will find the inorder of bst & store in an array then
        // we apply 2-pointer app to find the k

        vector<int> inorderArr;
        inorderTraversal(root, inorderArr);

        // now apply 2-pointer app
        int i=0, j=inorderArr.size()-1;
        while(i<j){
            if(inorderArr[i] + inorderArr[j]  == k){
                return true;
            }else if( inorderArr[i] + inorderArr[j]  > k ){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};
