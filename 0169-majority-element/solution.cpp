class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int potentialNo = nums[0];
        int cnt = 1;

        for(int x : nums){
            if( x == potentialNo) cnt++;
            else{
                cnt--;
            }
            if(cnt == 0){
                potentialNo = x;
                cnt = 1;
            }
        }

        return potentialNo;
    }
};
