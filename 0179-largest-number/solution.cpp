// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         // i thing if we convert this int array into string and sort it then i will sort as we wanted 


//         int n = nums.size();
//         vector<string> str(n);
//         for(int i=0; i<n; i++) str[i] = to_string(nums[i]);

//         // this will sort in ascending order but we want in descending order so either sort in descending 
//         // order or iterate the array in reverse order and store in ans string 

//         // *But still it will fails for [30, 3]  
       
//         sort(str.begin(), str.end());
//         for(int i=0; i<n; i++) cout<<str[i]<<" ";

//         string ans = "";
//         for(int i=n-1; i>=0; i--) ans+= str[i];

//         return ans;
//     }
// };



class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // i thing if we convert this int array into string and sort it then i will sort as we wanted 


        int n = nums.size();
        vector<string> str(n);
        for(int i=0; i<n; i++) str[i] = to_string(nums[i]);

        // custome sort 
        sort(str.begin(), str.end(), [](string a, string b){
            return a+b > b+a;
        });
        
        for(int i=0; i<n; i++) cout<<str[i]<<" ";

        string ans = "";
        for(string s : str) ans+=s;

        // Edge case: all zeros
        if (ans[0] == '0') return "0";

        return ans;
    }
};
