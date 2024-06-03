class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        //base case 
        if( nums.size() == 0) return ans;

        int begin=nums[0];
        int end = nums[0];
        for( int i=1; i<nums.size(); i++){
            if(nums[i-1] + 1  == nums[i] ){
                //continue // we are in continu part
            }
            else{  // our prev range has ended
               if( begin == end){
                ans.push_back(to_string(begin));
               }else{
                  string temp = "";
                  temp+=to_string(begin);
                  temp+="->";
                  temp+=to_string(end);

                  ans.push_back(temp);
               }
               // since our prev range has ended & this time the new range start
               // so store the begin no this new range in begin variable
               begin = nums[i];
            }

            //every time our end must be updated b/c end variable hold 
            // the last element of last range
            end = nums[i];
        }

        // pushing the last range explicetly
        if( begin == end){
            ans.push_back(to_string(begin));
        }else{
            string temp = "";
            temp+=to_string(begin);
            temp+="->";
            temp+=to_string(end);

            ans.push_back(temp);
        }
        
        return ans;
    }
};
