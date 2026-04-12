class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1;

        int mini = INT_MAX;
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(nums[s] == nums[mid] && nums[mid] == nums[e]){
                mini = min(mini, nums[s]);
                s++; e--;
            }
            else if(nums[s] <= nums[mid]){
                //means 1st half is sorted;
                mini = min(mini, nums[s]);
                s = mid+1;
            }else{
                // means 2nd half is sorted
                mini = min(mini, nums[mid]);
                e = mid-1;
            }
        }
        return mini;
    }
};
