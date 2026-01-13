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
    void inorderTraversal(TreeNode* root, vector<int> &inorderArr){
        // base case 
        if(root == NULL) return ;

        inorderTraversal(root->left, inorderArr);
        inorderArr.push_back(root->val);
        inorderTraversal(root->right, inorderArr);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        // do inorder traversal then we will get all the elements in sorted order then 
        // between all the consecutives we will the the min abs difference

        vector<int> inorderArr;
        inorderTraversal(root, inorderArr);

        int minDiff = INT_MAX; // just aise hi
        for(int i=1; i<inorderArr.size(); i++){
            minDiff = min( minDiff, abs(inorderArr[i] - inorderArr[i-1]));
        }
        return minDiff;
    }
};
