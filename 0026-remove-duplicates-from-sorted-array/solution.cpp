// @ MY SOLUTION -- SUBMIT
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        for( int i=1; i<nums.size(); i++){
            if( nums[i] != nums[j-1]){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j; 
    }
};



// // @ FROM DISCUSSION SECTION  -- SUBMIT
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int j=1;
//         for( int i=1; i<nums.size(); i++){
//             if( nums[i] != nums[i-1]){
//                 nums[j] = nums[i]; // not swap 
//                 j++;
//             }
//         }
//         return j; 
//     }
// };
