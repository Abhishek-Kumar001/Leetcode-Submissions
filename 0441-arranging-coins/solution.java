// class Solution {
//     public int arrangeCoins(int n) {
        
//         int i=1;
//         int cnt =0;
//         for( ; i<n; i++){
            
//             cnt+=i;
//             System.out.println(cnt + " " + i);
//             if(cnt > n) break;
//         }
//         return i-1;
//     }
// }
 
        
            // CHAT- GPT
// class Solution {
//     public int arrangeCoins(int n) {
//         int i = 1;
//         int cnt = 0;
//         while (cnt + i <= n) {
//             cnt += i;
//             i++;
//         }
//         return i - 1;
//     }
// }



          // chatGPT CODE
class Solution {
    public int arrangeCoins(int n) {
        long start = 0;
        long end = n;
        
        while (start <= end) {
            long mid = start + (end - start) / 2;
            long totalCoins = mid * (mid + 1) / 2;
            
            if (totalCoins == n) {
                return (int) mid;
            } else if (totalCoins < n) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return (int) end;
    }
}


