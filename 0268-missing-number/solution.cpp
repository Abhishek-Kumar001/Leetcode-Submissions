class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0, n = nums.size();

        while(i < n){

            if(nums[i] == n || nums[i] == i) i++;
            else{
                int correctInd = nums[i];
                swap(nums[i], nums[correctInd]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i) return i;
        }
        return n;
    }
};
