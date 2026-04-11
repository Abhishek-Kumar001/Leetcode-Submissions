class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);

        int n = numbers.size();
        int s = 0, e=n-1;

        while(s<e){
            int sum = numbers[s] + numbers[e];
            if(sum == target){
                ans[0] = s+1;
                ans[1] = e+1;
                return ans;
            }else if(sum > target) e--;
            else s++;
        }
        return ans;
    }
};
