class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        unordered_map<int, int> freq;
        
        // Step 1: Count frequency of each number
        for(int x : nums) {
            freq[x]++;
        }

        unordered_map<int, int> freqCount;

        // Step 2: Count frequency of frequencies
        for(auto &p : freq) {
            freqCount[p.second]++;
        }

        // Step 3: Traverse left to right
        for(int x : nums) {
            if(freqCount[freq[x]] == 1) {
                return x;
            }
        }

        return -1;
    }
};

