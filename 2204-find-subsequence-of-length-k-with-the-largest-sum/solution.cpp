class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                pq.push({nums[i], i});
            } else {
                if (nums[i] > pq.top().first) {
                    pq.pop();
                    pq.push({nums[i], i});
                }
            }
        }
        vector<int> index;
        while (!pq.empty()) {
            index.push_back(pq.top().second);
            pq.pop();
        }
        sort(index.begin(), index.end());

        vector<int> ans;
        for (int i = 0; i < index.size(); i++) {
            ans.push_back(nums[index[i]]);
        }
        return ans;
    }
};
