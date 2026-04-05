class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // look for the 1st element != val;
        
        int j=nums.size();  // vvi vvi vvi
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                j = i;
                break;
            }
        }

        for(int i=j+1; i<nums.size(); i++){
            if(nums[i] != val){
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return j;
    }
};
