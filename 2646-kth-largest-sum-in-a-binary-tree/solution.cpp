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


// class Solution {
// public:
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//         queue<TreeNode* > q;
//         q.push(root);

//         vector<long long> levelSumArr;
       
//         while(!q.empty()){
//             int size = q.size();
//             long long sum = 0;
//             for(int i=0; i<size; i++){
//                 auto node = q.front();
//                 q.pop();

//                 sum+=node->val;

//                 if(node->left)  q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//             levelSumArr.push_back(sum);
            
//         }

//         sort(levelSumArr.begin(), levelSumArr.end());
//         int n= levelSumArr.size();
//         if(k > n) return -1;
//         return levelSumArr[n-k];
        
//     }
// };



class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode* > q;
        q.push(root);

        // vector<long long> levelSumArr;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        int flag = 0; // indicate k is greater than the level of tree
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            for(int i=0; i<size; i++){
                auto node = q.front();
                q.pop();

                sum+=node->val;

                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // levelSumArr.push_back(sum);
            if(pq.size()  < k){
                pq.push(sum);
            }
            else{
                flag = 1;
                if(pq.top() < sum){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        if(pq.size() == k || flag == 1) return pq.top();
        return -1;
        
    }
};
