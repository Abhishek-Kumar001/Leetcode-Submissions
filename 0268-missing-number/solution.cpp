class Solution {
public:
//     int missingNumber(vector<int>& nums) {
        
//         int i=0;
//         while( i< nums.size()){
//            int corr = nums[i];
            
//            if(nums[i] < nums.size()  && nums[i] != nums[corr]){
//                swap( nums[i], nums[corr]);
//            }
//            else{
//                i++;
//            }
//         }
        
//         for(int i=0; i<nums.size(); i++){
//            if( nums[i] != i) return i;
//         }
//         return nums.size();
//     }
    
    int missingNumber(vector<int>& nums) {
        
        // method -2
        int xor1=0, xor2=0;
        for(int i=0; i<nums.size(); i++){
           xor1^= nums[i];
           xor2^=i;
        }
        xor2^=nums.size();
        
        return xor1 ^ xor2;
    }
};
