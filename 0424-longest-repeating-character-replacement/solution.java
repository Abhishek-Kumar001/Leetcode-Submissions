class Solution {
    public int characterReplacement(String s, int k) {
              // @ YT - code with Ease - by Varsha code 100% easy and succcess

        Map<Character, Integer> mp = new HashMap<>();
        int maxRepetCount = 0, start=0;
        int n = s.length();
        int maxLen = 0;
        for(int end =0; end<n; end++){
            char ch = s.charAt(end);
            if(mp.get(ch) != null){
               mp.put(ch, mp.get(ch)+1 );
            }else{
                mp.put(ch, 1);
            }        

            maxRepetCount = Math.max(maxRepetCount, mp.get(ch));

            int nonRepetCnt = (end - start+1) - maxRepetCount;

            if(k >= nonRepetCnt ){
                maxLen = Math.max(maxLen, (end- start + 1));
            }else{
                mp.put(s.charAt(start), mp.get(s.charAt(start))-1 );
                start++;
            }
        }
        return maxLen;
    }
}
