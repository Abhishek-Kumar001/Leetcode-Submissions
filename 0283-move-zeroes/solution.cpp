class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i;
        for(  i=0; i<nums.size(); i++){
            if(nums[i] == 0)  break;
        }
        
        for(int j=i+1; j<nums.size(); j++){
           if(nums[j] != 0){
               swap(nums[j], nums[i++]);
           }
        }
    }
};
