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
    TreeNode* buildTreeHelper(int &index, vector<int>& postorder, vector<int>&
                         inorder,map<int, int> &mpp, int startInd, int endInd)
    {
      
        //base case
        if(index >= postorder.size()  || startInd > endInd){
           return NULL;
        }
        // int val = preorder[index];
        TreeNode* root = new TreeNode(postorder[index]);
        int posi = mpp[postorder[index--]];
         // 1st make rigt call then left b/c it is postorder left-right-root  i.e in 
         //   reverse root->right->left
        root->right = buildTreeHelper(index, postorder, inorder, mpp, posi+1,
                                     endInd);

        root->left = buildTreeHelper(index, postorder, inorder, mpp, startInd,
                                     posi-1);
        
       return root;
    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        
        int n= postorder.size();
        int index = n-1;
       return buildTreeHelper(index, postorder, inorder, mpp, 0, n-1);
    }
};
