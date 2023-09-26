class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // striver code
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans(0, vector<int>(3));
        for(int i=0; i<n; i++){
            if( i!=0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;

            while( j < k){
                if( nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp{ nums[i], nums[j], nums[k]};
                    ans.push_back( temp );
                    j++; 
                    k--;
                    while( j< k &&  nums[j]== nums[j-1]) j++;
                    while( k > j && nums[k] == nums[k+1]) k--;
                }
                else if(  nums[i] + nums[j] + nums[k] > 0 ){
                    k--;
                    while( k > j && nums[k] == nums[k+1]) k--;
                }
                else{
                    j++;
                    while( j< k &&  nums[j]== nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};
