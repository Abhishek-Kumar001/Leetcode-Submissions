class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = -1;
        // first find 1st zero
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                k = i;
                break;
            }
        }
        if(k == -1) return;

        for(int i=k+1; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[k]);
                k++;
            }
        }
    }
};
