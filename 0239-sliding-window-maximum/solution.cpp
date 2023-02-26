class Solution {
public:
    //  app:- use deque ( copy past of TECH DOSE)    TC=O(N), SC=O(K)
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Pair<int,int>  == nums[i], i
        deque< pair<int, int> > dq;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            if( !dq.empty() && dq.front().second <= i-k ){  // removing front ele if it goes out of window size
                dq.pop_front();
            }
                
            while(!dq.empty()  && dq.back().first  < nums[i]){  // maintaining elements  in DEC order
                 dq.pop_back();
            }
            
            dq.push_back( make_pair(nums[i], i));  // push current NODE
            
            if( i >= k-1){
                ans.push_back(dq.front().first);  // including maxi of current window in ans vector
            }
        }
        return ans;
    }
};
