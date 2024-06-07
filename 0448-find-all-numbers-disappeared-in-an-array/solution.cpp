class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //cyclic sort
        int i=0;
        while(i<nums.size()){
            int correct = nums[i]-1;
            if(nums[i] != nums[correct]){
                swap(nums[i], nums[correct]);
            }
            else i++;
        }

        vector<int> ansVec;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1){
                ansVec.push_back(i+1);
            }
        }
        return ansVec;
    }
};
