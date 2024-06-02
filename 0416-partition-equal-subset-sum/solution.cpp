class Solution {
    bool subsetSumTarget(vector<int> &nums, int target){
        int n= nums.size();
        vector<int> prev(target+1, 0), curr(target+1, 0);
        // base case-1
        prev[0]= 1;
        //base case vvi
        if(nums[0] <= target){
            prev[nums[0]]= 1;
        }

        for(int i=1; i<n; i++){
            for(int tar=1; tar<=target; tar++){
                // take
                int take = 0;
                if( nums[i] <= tar){
                    take  = prev[tar-nums[i]];
                }
                //not take 
                int notTake = prev[tar];
        
                curr[tar] = take || notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it: nums){
            sum+=it;
        }

        if(sum % 2 == 1) return false;

        int target = sum / 2;

        return subsetSumTarget(nums, target);  
    }
};
