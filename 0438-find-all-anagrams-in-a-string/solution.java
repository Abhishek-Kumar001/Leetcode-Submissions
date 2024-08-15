// class Solution {
//     public List<Integer> findAnagrams(String s, String p) {
//         // my code but i thing it is not a optimal solution 
//         int n= s.length(), m = p.length();
//         if(n < m) return new ArrayList<>();

//         int occurence[] = new int[26];
//         for(int i=0; i<p.length(); i++){
//             char ch = p.charAt(i);
//             occurence[ch - 'a']++;
//         }

//         List<Integer> al = new ArrayList<Integer>();
//         for(int i=0; i<n; i++){
//             char ch = s.charAt(i);
//             if(occurence[ch- 'a'] > 0){  // if this char is present then only check
//                 if(i+m <= n){
//                     boolean result = isAnagram(s.substring(i, i+m), p);
//                     if(result)al.add(i);
//                 }else{
//                     return al;
//                 }
//             }          
//         }
//         return al;
//     }

//     public boolean isAnagram(String s, String p){
//         int occurence[] = new int[26];
//         for(int i=0; i<p.length(); i++){
//             char ch = p.charAt(i);
//             occurence[ch - 'a']++;
//         }

//         for(int i=0; i<p.length(); i++){
//             char ch = s.charAt(i);
//             occurence[ch - 'a']--;
//         }

//         for(int i=0; i<26; i++){
//             if(occurence[i] >= 1) return false;
//         }
//         return true;
//     }
// }


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
