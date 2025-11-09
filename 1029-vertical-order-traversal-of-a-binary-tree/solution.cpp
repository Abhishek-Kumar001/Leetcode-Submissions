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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            // Directly push into mpp[col][row]
            mpp[col][row].push_back(node->val);

            // Push children
            if(node->left)  q.push({node->left,  {row + 1, col - 1}});
            if(node->right) q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;
        for(auto &colPair : mpp){                 // col -> map<row, vector<int>>
            vector<int> colVals;
            for(auto &rowPair : colPair.second){  // row -> vector<int>
                auto &vals = rowPair.second;
                sort(vals.begin(), vals.end());
                for(int x : vals){
                    colVals.push_back(x);
                }
            }
            ans.push_back(colVals);
        }

        return ans;
    }
};

