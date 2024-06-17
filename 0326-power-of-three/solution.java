// class Solution {
//     public boolean isPowerOfThree(int n) {
//         if(n <= 0 ) return false;
//         if(n == 1) return true;

//         int s=1, e=n/3;
//         while(s<=e){
//             int mid =(s+e)/2;

//             int result = isPowerOfTreeBinarySearch(mid, n);
//             if(result == 0) return true;
//             else if(result == 1) e=mid-1;
//             else s= mid+1;
//         }
//         return false; 

//     }
//     public int isPowerOfTreeBinarySearch(int i, int n){
//         int result = 1;
//         for(int ii = 1; ii<=i; ii++){
//             result*=3;

//             if(result > n) return 1;
//         }
//         if(result == n) return 0;
//         else return -1;
//     }

// }


class Solution {
    public boolean isPowerOfThree(int n) {
        if (n <= 0) return false; // negative numbers and zero are not powers of three

        while (n % 3 == 0) {
            n /= 3; // repeatedly divide by 3
        }

        return n == 1; // if we reduce n to 1, it is a power of three
    }
}

