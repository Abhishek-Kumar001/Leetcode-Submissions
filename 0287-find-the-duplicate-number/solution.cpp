class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we will do cyclic sort and place all the numbers to its correct positions
        int s = 0, e = nums.size();

        while(s <= e-1){  // < or <= doesn't mattar
            if(nums[s] == s+1) s++; // as it is at its correct position
            else{
                int correctInd = nums[s]-1;
                // agar its correct index pe v wahi hai then this is duplicate
                if(nums[s] == nums[correctInd]) return nums[s];
                // else swap with its correct index value
                swap(nums[s], nums[correctInd]);
            }
        }

        // now travers all the element of arr and find the number which is not
        // on its correct position
        for(int i=0; i<e; i++) if(nums[i] != i+1) return nums[i];

        return -1;
    }
};
