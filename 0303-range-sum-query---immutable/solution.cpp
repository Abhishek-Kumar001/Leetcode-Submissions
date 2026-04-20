class NumArray {
    vector<int> prefixArr;
public:
    NumArray(vector<int>& nums) {
        prefixArr.resize(nums.size());
        prefixArr[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            prefixArr[i] = prefixArr[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefixArr[right];
        return prefixArr[right] - prefixArr[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
