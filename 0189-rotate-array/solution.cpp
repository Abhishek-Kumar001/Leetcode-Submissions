class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        vector<int> temp(k);
        int j=0;
        for( int i=nums.size()-k; i<nums.size(); i++){
             temp[j++] = nums[i];
        }
        // now shift the all n-k elements to the left 
        for( int i=nums.size()-k-1; i>=0; i--){
           nums[i+k] = nums[i];
        }
        //now put all k extracted elements to the starting
        for( int i=0; i<k; i++){
           nums[i] = temp[i];
        }
        
    }
};
