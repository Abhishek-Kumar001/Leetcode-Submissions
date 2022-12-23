class Solution {
public:
    void swap(vector<int> &arr, int start, int end){
        int temp= arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        int start=0;
        int end = nums.size();

        while( start<end){
            if(nums[start] == INT_MIN){  // since int can't store INT_MIN-1  in line no 16
                start++; continue;
            }
            int correct = nums[start] -1;

            if( nums[start]>0 && nums[start]<=end  &&  nums[start] != nums[correct]){
                swap(nums, start, correct);
            }
            else{
                start++;
            }

           
        }
        for(int i=0; i<end; i++){
                if( nums[i] != i+1){
                    return i+1;
                }
        }
        return nums.size()+1;    
    }
};
