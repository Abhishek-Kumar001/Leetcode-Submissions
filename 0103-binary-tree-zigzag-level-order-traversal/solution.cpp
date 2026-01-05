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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};   // 🔴 Important fix
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size, -1);
            for(int i=0; i<size; i++){
                int p = flag  ? i : size-1-i;
                TreeNode* top = q.front();
                q.pop();
                temp[p] = top->val;

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            flag = !flag;
            ans.push_back(temp);
        }

        return ans;
    }
};
