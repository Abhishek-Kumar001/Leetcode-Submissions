class Solution {
    public int lengthOfLongestSubstring(String s) {
        // my 1st time submited code (apna college + my logic)
        int n = s.length();
        if (n == 0)
            return 0;

        int indexOfChar[] = new int[256];
        for (int i = 0; i < 256; i++)
            indexOfChar[i] = -1;

        int maxLen = 0, start = -1;
        for (int i = 0; i < n; i++) {

            if (indexOfChar[s.charAt(i)] > -1 ){
                if( indexOfChar[s.charAt(i)] >= start) {
                    // maxLen = Math.max(i - start, maxLen);
                    start = indexOfChar[s.charAt(i)] ;
                }else{
                    maxLen = Math.max(i - start, maxLen);
                }
            } else {
                maxLen = Math.max(i - start, maxLen);
            }
            indexOfChar[s.charAt(i)] = i;

        }
        // if(start == -1)return n;

        return maxLen;
    }
}
