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
    TreeNode* setParentAndReturnStartNode(TreeNode* root, map<TreeNode* , TreeNode*> 
                                          &parentMpp, int start)
    {
        //we will do level order treaversal and store parent and find startNode
        queue<TreeNode* > q;
        q.push(root);
        TreeNode* res ;

        while(!q.empty()){        
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start) {
                res = node;
                return res;; // i think no need to go further
            }
            
            if(node->left){
                parentMpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentMpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int requireTime(TreeNode* startNode, map<TreeNode* , TreeNode*> &parentMpp){
        map<TreeNode*, int > visited;
        visited[startNode] = true;
        queue<TreeNode* > q;
        q.push(startNode);

        int time = 0; 
        
        while(! q.empty()){
            int size = q.size();
            bool flag = 0;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left  &&  !visited[node->left]){
                    flag = true;
                    visited[node->left]= true;
                    q.push(node->left);
                }
                if(node->right &&  !visited[node->right]){
                    flag = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parentMpp[node]  &&  !visited[parentMpp[node]]){
                    flag = true;
                    visited[parentMpp[node]] = true;
                    q.push(parentMpp[node]);
                }

            }       
            if(flag == true) time++;
        }
        return time;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* , TreeNode*> parentMpp ;
        TreeNode* startNode = setParentAndReturnStartNode(root, parentMpp, start);

        return requireTime(startNode, parentMpp);
        
    }
};







