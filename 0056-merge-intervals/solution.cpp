class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<int> arr(intervals[0]);
        vector<vector<int>> ans;
        for(int i=1; i<intervals.size(); i++){
            if(arr[1] >= intervals[i][0]){
                arr[1] = max(arr[1], intervals[i][1]);
            }else{
                ans.push_back(arr);
                arr = intervals[i];
            }
        }
        ans.push_back(arr);
        return ans;
    }
};
