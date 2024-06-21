class Solution {
    public int countSegments(String s) {
        s = s.trim();
        if(s.length() == 0) return 0;

        int cntWord = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == ' ' && s.charAt(i-1) != ' '){
                cntWord++;
            }
        }
        return cntWord+1;
    }
}
