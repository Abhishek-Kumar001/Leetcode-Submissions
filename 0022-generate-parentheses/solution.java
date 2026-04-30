class Solution {
    public void helper(int open, int close, String s, List<String> ans){
        if(open == 0 && close == 0){
            ans.add(s);
            return ;
        } 
        

        if(open != 0){
            s+="(";
            helper(open - 1, close, s, ans);
            s =  s.substring(0, s.length()-1);
        }

        if(open < close){
            s += ")";
            helper(open, close-1, s, ans);
            s = s.substring(0, s.length()-1);
        }
    }
    public List<String> generateParenthesis(int n) {
       List<String> ans = new ArrayList<String>(); // ✅
        String s = "";
        helper(n, n, s, ans);
        return ans;
    }
}
