class Solution {
    public String removeUnwantedChar( String s){
        String ans = "";

        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            if( (ch >=65 && ch <=90)  || (ch >=97 && ch <= 122) ){
                ans+= Character.toLowerCase(ch);
            }else if( ch >= 48 && ch <= 57) ans += ch;
        }

        return ans;
    }

    public boolean isPalindromeHelper(String s){
        int n = s.length();
        for(int i=0; i<n/2; i++){
            if(s.charAt(i) != s.charAt(n-1-i)) return false;
        }
        return true;
    }
    public boolean isPalindrome(String s) {
        s = removeUnwantedChar(s);

        return isPalindromeHelper(s);
    }
}
