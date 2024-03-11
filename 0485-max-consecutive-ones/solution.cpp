class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxOne=0;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                 cnt++;    
                 // maxOne = max( cnt, maxOne);  
            }
            else{
                maxOne = max( cnt, maxOne);
                cnt=0;
            }
        }
        maxOne = max( cnt, maxOne);  // vvi
        return maxOne;
    }
};
