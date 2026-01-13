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
    void inorderTraversal(TreeNode* root, vector<int>& inorderArr) {
        if (!root) return;
        inorderTraversal(root->left, inorderArr);
        inorderArr.push_back(root->val);
        inorderTraversal(root->right, inorderArr);
    }

public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};

        vector<int> inorderArr;
        inorderTraversal(root, inorderArr);

        vector<int> ans;
        int maxOcc = 0;
        int currCount = 0;
        int currVal = inorderArr[0];

        for (int val : inorderArr) {
            if (val == currVal) {
                currCount++;
            } else {
                if (currCount > maxOcc) {
                    ans.clear();
                    ans.push_back(currVal);
                    maxOcc = currCount;
                } else if (currCount == maxOcc) {
                    ans.push_back(currVal);
                }
                currVal = val;
                currCount = 1;
            }
        }

        // Handle last value group
        if (currCount > maxOcc) {
            ans.clear();
            ans.push_back(currVal);
        } else if (currCount == maxOcc) {
            ans.push_back(currVal);
        }

        return ans;
    }
};

