class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        sort(nums.begin(),nums.end());
        int dif=0;
        int maxDif = INT_MIN;
        for(int i=1; i<nums.size(); i++){
            dif=nums[i]-nums[i-1];
            maxDif=max(maxDif,dif);
        }
        return maxDif;
    }
};
