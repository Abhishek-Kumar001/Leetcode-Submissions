class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();


        long long prevTake = nums[0];
        long long prevSkip = 0;

        for(int i=1; i<n; i++){
            long long take = 0;
            long long skip = 0;

            if(colors[i] == colors[i-1]){
                take = prevSkip + nums[i];
            }else{
                take = max(prevSkip, prevTake) + nums[i];
            }

            skip = max(prevSkip, prevTake);

            prevTake = take;
            prevSkip = skip;
        }

        return max(prevTake, prevSkip);
    }
};
