class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        int miniSize = INT_MAX;
        int s = 0;
        for(int i=0; i<n; i++){
           sum+=nums[i];
           if(sum >= target ){
              while(sum >= target && s <= i){
                miniSize = min(miniSize, i-s+1);
                sum-=nums[s];
                s++;
              }
           }
        }
        return miniSize == INT_MAX ? 0 : miniSize;
    }
};
