class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product =1;
        int zero =0;
        for(int i=0; i<nums.size(); i++){
            if( nums[i])
               product*=nums[i];
            else zero++;
        }
        
        vector<int> ans(nums.size());

        for(int i=0; i<nums.size(); i++){
            if(nums[i]){
                if(zero>=1){
                    ans[i] =0;
                }else{
                     ans[i] = product / nums[i];
                }
            }           
            else{
                //zero--;
                if( zero > 1){
                    ans[i] =0;
                }
                else{
                   ans[i] = product;
                }
            }
             
        }
        
        return ans;
    }
};
