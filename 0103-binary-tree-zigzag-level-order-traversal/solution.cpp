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

        if(!root) return {}; // handle empty tree

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> temp;
        vector<vector<int>> ans;

        int flag = 1;

        while(!q.empty()) {
            TreeNode* frontEle = q.front();
            q.pop();

            if(frontEle != NULL) {

                temp.push_back(frontEle->val);

                // fix: push children of frontEle, not root
                if(frontEle->left) q.push(frontEle->left);
                if(frontEle->right) q.push(frontEle->right);
            }
            else {
                // reverse properly
                if(flag) ans.push_back(temp);
                else {
                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                }

                temp.clear();
                flag = !flag;

                // stop if no more nodes
                if(q.empty()) break;

                q.push(NULL);

                if(q.size() == 1) break;
            }
        }
        return ans;
    }
};

