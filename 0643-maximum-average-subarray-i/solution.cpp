class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double temp = 0;
        double ans = 0;

        for(int i=0; i<k; i++){
            temp+=nums[i];
        }

        ans = temp / k;

        for(int i=k; i<nums.size(); i++){
            temp-= nums[i-k];
            temp+= nums[i];

            ans = max( ans, temp/k);
        }

        return ans;
    }
};
