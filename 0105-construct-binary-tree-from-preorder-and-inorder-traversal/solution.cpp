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
    TreeNode* buildTreeHelper(int &index, vector<int>& preorder, vector<int>&
                         inorder,unordered_map<int, int> &mpp, int startInd, int endInd)
    {
      
        //base case
        if(index >= preorder.size()  || startInd > endInd){
           return NULL;
        }
        // int val = preorder[index];
        TreeNode* root = new TreeNode(preorder[index]);
        int posi = mpp[preorder[index++]];
        root->left = buildTreeHelper(index, preorder, inorder, mpp, startInd,
                                     posi-1);
        root->right = buildTreeHelper(index, preorder, inorder, mpp, posi+1,
                                     endInd);

       return root;
    
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for(int i=0; i<preorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        
        int n= preorder.size();
        int index = 0;
       return buildTreeHelper(index, preorder, inorder, mpp, 0, n-1);

    }
};
