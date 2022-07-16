class Solution {
public:
   int majorityElement(vector<int>& nums) {
       int count = 0;
       int candidate = 0;
       
       for(int val : nums){
           if(count == 0){
              candidate = val;
           }
           if(val == candidate ){
               count +=1;
           }
           else{
               count -=1;
           }
       }
       
       return candidate;
   }
};
