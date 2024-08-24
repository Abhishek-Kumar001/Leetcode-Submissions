class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // vvvi base case // a/c to constraits & problem statement
        if(k <= 1) return 0;  // vvvi to handle 


        int start = 0, productSoFar = 1, cnt = 0;

        for(int end = 0; end<nums.size(); end++){
            productSoFar*=nums[end];
            while(productSoFar >= k){
                productSoFar/=nums[start];
                start++;
            }
            cnt+=(end-start+1);
        }
        return cnt;
    }
};
