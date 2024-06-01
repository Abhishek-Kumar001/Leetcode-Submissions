// Approach  -- **** FROM DISCUSSION ****
// Make some modifications to the sort function to maximize the number value.
// For example:- array = [2,20,1,100]

// Simple Sort Function:-
// A simple sort function sorts the array in ascending order without any constraints.
// after sorting array = [1,2,20,100]

// Custom Sort Function:-
// In a custom sort function we can put some constraints to sort the array, here I have put a constraint to check the pair of integers-
// to_string(a)+to_string(b)>to_string(b)+to_string(a)
// If this statement is true then a comes first in the array otherwise b comes first.
// after sorting array = [2,20,1,100]

// Note:-In sorted array we can check that above statement is true for all pairs.
// 220>202 [2,20]
// 21>12 [2,1]
// 2100>1002 [2,100]
// 201>120 [20,1]
// 20100>10020 [20,100]
// 1100>1001 [1,100]

// Complexity
// Time complexity:O(N*log(N))
// Space complexity:O(1)



bool compare(int a,int b)
{
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
class Solution {
public:
    string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        string ans = "";
        for(int i = 0;i<arr.size();i++)
        ans+=to_string(arr[i]);
        if(ans[0]=='0') return "0";
        return ans; 
    }
};


  // OR FOR BETTER UNDERSTING U CAN REFER THIS CODE ALSO

// class Solution {
// public:
// static bool mycom(string a,string b)
// {
//     string t1=a+b;
//     string t2=b+a;
//     return t1>t2;
// }
//     string largestNumber(vector<int>& nums) {
//         vector<string>v;
//         for(auto i:nums)
//         {
//             v.push_back(to_string(i));
//         }
//         sort(v.begin(),v.end(),mycom);
//         if(v[0]=="0")
//         return "0";
//         string ans="";
//         for(auto i:v)
//         {
//             ans+=i;
//         }
//         return ans;

//     }
// };
