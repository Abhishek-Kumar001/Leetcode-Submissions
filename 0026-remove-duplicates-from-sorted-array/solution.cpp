class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        for( int i=1; i<n;){
            if( nums[i] == nums[i-1]){
                nums.erase( nums.begin()+i  );
                n--;
            }
            else{
                i++;
            }
        }
        return nums.size();   
    }
};
