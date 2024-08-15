class Solution {
    public boolean checkInclusion(String s1, String s2) {
        // just using 438 find all anagrams in a string code 
        Solution2 obj = new Solution2();

        return obj.findAnagrams(s2, s1);
    }
}

class Solution2 {
    // make it's return type as boolean because we need and in t/f
    public boolean findAnagrams(String s, String p) {
        // yt - Tech dose 
        int n= s.length(), m = p.length();
        if(n < m)  
         // return new ArrayList<>();
         return  false;

        int occurenceS[] = new int[26];
        int occurenceP[] = new int[26];

        int i = 0;
        for( i=0; i<p.length(); i++){
            occurenceS[ s.charAt(i) - 'a']++;
            occurenceP[ p.charAt(i) - 'a']++;
        }

        // List<Integer> al = new ArrayList<Integer>();
      
        int start = 0, end = i-1;
        while(end<n){
            if(compareOccurence(occurenceS, occurenceP)){
                // al.add(start);
                return true;
            }

            end++;
            if(end < n){
                occurenceS[s.charAt(end) - 'a']++;
            }
            occurenceS[s.charAt(start) - 'a']--;
            start++;
        }
        // return al;
        return false;
    }
    private boolean compareOccurence(int []occurenceS, int []occurenceP){
        for(int i=0; i<occurenceS.length; i++){
            if(occurenceS[i] != occurenceP[i]) return false;           
        }
        return true;
    }
}
