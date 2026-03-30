class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;
        int sMap[] = new int[26];

        for(int i=0; i<s.length(); i++){
            sMap[s.charAt(i) - 97]++;
        }

        for(int i=0; i<t.length(); i++){
            if(sMap[t.charAt(i) - 97] >= 1)
               sMap[t.charAt(i) - 97]--;
            else return false;
        }

        return true;
    }
}
