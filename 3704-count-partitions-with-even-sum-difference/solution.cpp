class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int  x : nums) sum+=x;
        
        int tempSum = 0;
        int cnt= 0;
        for(int i=0; i<nums.size()-1; i++){
            tempSum +=nums[i];
            
            int secondSum = sum - tempSum;
            
            if( (secondSum - tempSum) % 2 == 0) cnt++; 
        }
        
        return cnt;
    }
};
