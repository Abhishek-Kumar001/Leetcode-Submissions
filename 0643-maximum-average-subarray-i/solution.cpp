class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
       // double maxAvg = 0; // vvvi -  0 se initialize na kare
        double maxAvg = -DBL_MAX;  // vvvi 
        // there is no DBL_MIN fun in c++ only DBL_MAX fun is avilable 
       
        for(int i=0; i<nums.size(); i++){
            if(i < k){
                sum+=nums[i];
                if(i+1 == k)
                   maxAvg = max(maxAvg, sum/k);
            }
            else{
                sum-=nums[i-k];
                sum+=nums[i];
                maxAvg = max(maxAvg, sum/k);
            }
        }
        return maxAvg;
    }
};
