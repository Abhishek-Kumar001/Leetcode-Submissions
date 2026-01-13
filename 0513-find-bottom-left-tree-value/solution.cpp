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
    void leftViewTraversal(TreeNode* root, vector<int> &leftViewArr, int level){
        // base case
        if(root == NULL) return ;

        if(level == leftViewArr.size()){
            leftViewArr.push_back(root->val);
        }

        leftViewTraversal(root->left, leftViewArr, level+1);
        leftViewTraversal(root->right, leftViewArr, level+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        // if we do left view and store it the the last element in the left view will the the leftmost
        // value in the row of the tree;

        vector<int> leftViewArr;
        leftViewTraversal(root, leftViewArr, 0);
        return leftViewArr[leftViewArr.size() - 1];
    }
};
