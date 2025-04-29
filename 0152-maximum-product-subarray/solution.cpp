// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxProduct = nums[0]; // handle negative numbers too
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             long long tempProduct = 1; // reset for each new subarray start
//             for (int j = i; j < n; j++) {
//                 tempProduct *= nums[j]; // multiply nums[j], not nums[i]
//                 maxProduct = max(maxProduct, (int)tempProduct);
//             }
//         }

//         return maxProduct;
//     }
// };







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int maxProduct = nums[0]; // handle negative numbers too
        int n = nums.size();
        int leftSubArrayProduct = 1, rightSubArrayProduct = 1;

        for(int i=0; i<n; i++){


            leftSubArrayProduct *=nums[i];
            rightSubArrayProduct *=nums[n-1-i];

            maxProduct = max(maxProduct, max(leftSubArrayProduct, rightSubArrayProduct));

            // handle 0
            leftSubArrayProduct = leftSubArrayProduct == 0 ? 1 : leftSubArrayProduct;
            rightSubArrayProduct = rightSubArrayProduct == 0 ? 1 : rightSubArrayProduct;
        }
        return maxProduct;
    }
};








// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         if(nums.size() == 1) return nums[0];
//         int maxProduct = nums[0]; // handle negative numbers too
//         int n = nums.size();
//         int cntNegatives = 0;
//         for(int x : nums){
//             if(x < 0) cntNegatives++;
//         }
//         long long tempProduct = nums[0]; // reset for each new subarray start
//         if(nums[0] < 0) cntNegatives--;

//         for (int i = 1; i < n; i++) {
//             if( nums[i] < 0 && cntNegatives == 1){ 
//                 maxProduct = max(maxProduct, (int)tempProduct);
//                 tempProduct = 1;   
//                 cntNegatives--;         
//             }else if(nums[i] == 0){
//                 maxProduct = max(maxProduct, 0);
//                 tempProduct = 1;   
//             }
//             else{
//                 tempProduct *= nums[i]; // multiply nums[i]
//                 maxProduct = max(maxProduct, (int)tempProduct);
//             }        
//         }

//         return maxProduct;
//     }
// };




