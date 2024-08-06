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
    bool isValidBSTHelper(TreeNode* root, long minRange, long maxRange){
        //base case
        if(root == NULL) return true;

        if(root->val <=minRange  || root->val >= maxRange) return false;

        bool left = isValidBSTHelper(root->left, minRange, root->val);
        if(left == false) return false;
        bool right = isValidBSTHelper(root->right, root->val, maxRange);

        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {

        return isValidBSTHelper(root, LONG_MIN,LONG_MAX);
    }
};
