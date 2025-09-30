class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> copy(nums);
        int n=nums.size();
        while(n>=2){
            for(int i=0; i<n-1; i<i++){
                copy[i] = (copy[i] + copy[i+1]) % 10;
            }
            n--;
        }
        return copy[0];
    }
};
