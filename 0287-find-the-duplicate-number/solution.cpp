class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        while(s<=e){
            int correctPosi = nums[s]-1;
            if(nums[s] != nums[correctPosi]){
                swap(nums[s], nums[correctPosi]);
            }else{
                s++;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1) return nums[i];
        }

        return -1;
    }
};
