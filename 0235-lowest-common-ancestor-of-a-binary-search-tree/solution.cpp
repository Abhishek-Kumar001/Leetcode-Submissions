/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

          // my code // 
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //base case
//         if(root == NULL ) return NULL;
      
//         if(root->val == p->val || root->val == q->val) return root;

//         TreeNode* left = NULL;
//         if( root->val > p->val || root->val > q->val ){
//             left = lowestCommonAncestor(root->left, p, q);
//         }
        
//         TreeNode* right = NULL;
//         if(root->val < p->val || root->val < q->val){
//             right = lowestCommonAncestor(root->right, p, q);
//         }

//         if(left != NULL && right != NULL) return root;
//         if(left != NULL) return left;
//         if(right != NULL) return right;
//         return NULL;
//     }
// };

                // striver codee
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL ) return NULL;
      
        if( root->val > p->val && root->val > q->val ){
            return lowestCommonAncestor(root->left, p, q);
        }
       
        if(root->val < p->val && root->val < q->val){
            return  lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
    }
};
