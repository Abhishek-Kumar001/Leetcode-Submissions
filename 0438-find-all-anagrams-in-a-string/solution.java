class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        // yt - Tech dose 
        int n= s.length(), m = p.length();
        if(n < m) return new ArrayList<>();

        int occurenceS[] = new int[26];
        int occurenceP[] = new int[26];

        int i = 0;
        for( i=0; i<p.length(); i++){
            occurenceS[ s.charAt(i) - 'a']++;
            occurenceP[ p.charAt(i) - 'a']++;
        }

        List<Integer> al = new ArrayList<Integer>();
        
        
        int start = 0, end = i-1;
        while(end<n){
            if(compareOccurence(occurenceS, occurenceP)){
                al.add(start);
            }

            end++;
            if(end < n){
                occurenceS[s.charAt(end) - 'a']++;
            }
            occurenceS[s.charAt(start) - 'a']--;
            start++;
        }
        return al;
    }
    private boolean compareOccurence(int []occurenceS, int []occurenceP){
        for(int i=0; i<occurenceS.length; i++){
            if(occurenceS[i] != occurenceP[i]) return false;           
        }
        return true;
    }
}
