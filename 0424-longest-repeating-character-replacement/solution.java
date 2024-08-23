class Solution2 {
    public int characterReplacement(String s, int k) {
      // @ YT - code with Ease - by Varsha code 100% easy and succcess

        Map<Character, Integer> mp = new HashMap<>();
        int maxRepetCount = 0, start=0;
        int n = s.length();
        int maxLen = 0;
        for(int end =0; end<n; end++){
            char ch = s.charAt(end);
            mp.put(ch, mp.getOrDefault(ch, 0)+1 );
            
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


class Solution {
    public int characterReplacement(String s, int k) {
      // @ YT - code with Ease - by Varsha code 100% easy and succcess

      Map<Character, Integer> mp = new HashMap<>();
      int  maxMatch =0, maxLen = 0, start = 0;
      for(int i=0; i<s.length(); i++){
        char ch = s.charAt(i);
        mp.put(ch, mp.getOrDefault(ch, 0)+1);

        maxMatch = Math.max(maxMatch, mp.get(ch));
        int notMatch = (i-start+1) - maxMatch;

        if(notMatch <= k){
            maxLen = Math.max(maxLen, i-start+1);
        }else{
            mp.put(s.charAt(start), mp.get(s.charAt(start))-1);
            start++;
        }
      }
      return maxLen;
    }
}




