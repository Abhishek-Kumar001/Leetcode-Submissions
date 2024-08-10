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
        //base case 
        if(root == NULL) return;

        inorderTraversal(root->left, inorderArr);
        inorderArr.push_back(root->val);
        inorderTraversal(root->right, inorderArr);
    }
    TreeNode* createBalanceBT(vector<int> &inorderArr, int s, int e){
        if(s > e) return NULL;

        int mid = (s+e)/2;

        TreeNode* root = new TreeNode(inorderArr[mid]);

        root->left = createBalanceBT(inorderArr, s, mid-1 );
        root->right = createBalanceBT(inorderArr, mid+1, e);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderArr;
        inorderTraversal(root, inorderArr);
        int s = 0;
        int e = inorderArr.size()-1;
        return createBalanceBT(inorderArr,s,e);
    }
};
