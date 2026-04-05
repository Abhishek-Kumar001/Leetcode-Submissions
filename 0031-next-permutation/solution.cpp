class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //
        int n = nums.size();
        int ind = -1;
        for(int i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                ind = i-1;
                break;
            }
        }
        if(ind == -1){
           reverse(nums.begin(), nums.end());
           return;
        }

        int k = ind+1;
        for(int i=k+1; i<n; i++){
            if(nums[i] > nums[ind] && nums[i] < nums[k]) k = i;
        }

        swap(nums[ind], nums[k]);
        sort(nums.begin()+ind+1, nums.end());

        return;
    }
};
