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
    int kthSmallest(TreeNode* root, int k) {
        // as we know that the inorder traversal of bst store elements in ascending order
        vector<int> inorderArr;
        inorderTraversal(root, inorderArr);
        //now inorderArr has values of bst in ascending order
        // k-th smallest ele = k-1 th index element 
        return inorderArr[k-1];
    }
};
