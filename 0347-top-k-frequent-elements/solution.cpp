class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: frequency count
        for (const int &x : nums) {
            freq[x]++;
        }

        // bucket[f] = elements having frequency f
        vector<vector<int>> bucket(nums.size() + 1);

        for (const auto &[num, f] : freq) {
            bucket[f].push_back(num);
        }

        // Step 2: collect top k
        vector<int> ans;
        ans.reserve(k);

        for (int i = bucket.size() - 1; i > 0; i--) {
            for (const int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
