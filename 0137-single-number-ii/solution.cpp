class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        if (nums.size() == 1)
            return nums[0];

        for (int i = 2; i < nums.size(); i += 2) {
            if (nums[i] != prev)
                return prev; // it means the prev no. don't has 3 occerence
            // else  this no has 3 occerence;
            //  so check for next no. and next no. is:-  nums[i+1]
            prev = nums[i + 1];
            i++;
        }
        return prev;
    }
};
