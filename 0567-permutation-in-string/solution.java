class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int []occuranceOfs1 = new int[26];
        int n1 = s1.length();
        int n2 = s2.length();

        for(int i=0; i<s1.length(); i++){
            char ch = s1.charAt(i);
            occuranceOfs1[ch - 97]++;
        }
        
        int i=0;
        for(i=0 ; i<s2.length(); i++ ){
            char ch = s2.charAt(i);
            if(occuranceOfs1[ch - 97] != 0){
                break;
            }
        }
        int start = i;
        if(i + n1 > n2) return false;

        int end = i + n1;
        int []occuranceOfStr = new int[26];
        for(int ii=i; ii<i+n1; ii++){
            char ch = s2.charAt(ii);
            occuranceOfStr[ch - 97]++;
        }

        while(end < s2.length()){
            if(isSame(occuranceOfStr, occuranceOfs1)) return true;
            
            //start--;
            occuranceOfStr[s2.charAt(start) - 97]--;
            start++;

            occuranceOfStr[ s2.charAt(end) - 97]++;
            end++;

        }

        return isSame(occuranceOfStr, occuranceOfs1);
    }

    boolean isSame(int s1[], int s2[]){
        for(int i=0; i<26; i++){
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
}
