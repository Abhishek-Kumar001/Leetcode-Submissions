class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind= -1;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                ind = i-1;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return ;
        }

        int maxValInd = ind;
        for(int i=ind+1; i<nums.size(); i++){
            if(nums[i] > nums[ind]){
                maxValInd = i;
            }
        }

        swap(nums[ind], nums[maxValInd]);
        sort(nums.begin()+ind+1, nums.end());
        return ;
    }
};
