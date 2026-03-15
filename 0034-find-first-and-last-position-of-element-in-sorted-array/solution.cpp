class Solution {
    int Find1stPosition(vector<int> &nums, int target){
        int ans = -1;
        int s=0, e=nums.size()-1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                // this could be the 1st or may be not so store it and look in left
                ans = mid;
                e = mid-1;
            }else if(nums[mid] < target) s = mid+1;
            else e = mid-1;
        }

        return ans;
    }

    int FindLastPosition(vector<int> &nums, int target){
        int ans = -1;
        int s=0, e=nums.size()-1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                // this could be the last or may be not so store it and look in right
                ans = mid;
                s = mid+1;
            }else if(nums[mid] < target) s = mid+1;
            else e = mid-1;
        }

        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = Find1stPosition(nums, target);
        if(i == -1) return {-1, -1};
        int j = FindLastPosition(nums, target);
        return {i, j};
    }
};
