// @tech dose mathod

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1, n = nums.size();
        for(int i=n-1; i>0; i--){
            if( nums[i-1] < nums[i]){
                k = i-1;
                break;
            }
        }

        // it means arrays is in descending order in this case next permutation is 
        // reversed(or  starting,  or sorted array) a/c question
        if(k == -1){
            reverse(nums.begin(), nums.end());
            return ;
        }

        // next permuatation need to found
        int replaceIndex = k+1;
        for(int i=k+2; i< n; i++){
            if( nums[i] > nums[k] && nums[i] < nums[replaceIndex] ){
                replaceIndex = i;
            }
        }
        
        swap(nums[k], nums[replaceIndex]);
        cout<< nums[k]<< "   "<< nums[replaceIndex];
        sort(nums.begin()+(k+1), nums.end());
    }
};
