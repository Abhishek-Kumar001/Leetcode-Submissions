class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        int closestSum = nums[0] + nums[1] + nums[2]; // for now take 

        for(int i=0; i<n-2; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;

            int j=i+1, k = n-1;
            while(j<k){
                if(j != i+1 && nums[j] == nums[j-1]){
                    j++; continue;
                }
                if(k != n-1 && nums[k] == nums[k+1]){
                    k--; continue;
                }

                int sum = nums[i] + nums[j] + nums[k];

                // ✅ compare differences, but store the actual sum
                if (abs(sum - target) < abs(closestSum - target))
                    closestSum = sum;

                if (sum == target) return sum; // can't do better

                if(sum > target) k--;
                else j++;
            }
        }
        return closestSum;
    }
};
