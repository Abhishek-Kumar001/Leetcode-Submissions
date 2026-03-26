// class Solution {
//     public String simplifyPath(String path) {
//         String copyPath = path;
//         String dictionary[] = copyPath.split("/");
//         Stack<String> stk = new Stack<String>();

//         for(String str : dictionary){
//             if(str == ".."){
//                 if(!stk.empty()){
//                     stk.pop();
//                 }
//             }else if(str== "." || str == ""); // do nothing
//             else{
//                 stk.push(str);
//             }
//         }
//         Stack<String> stk2 = new Stack<>();
//         while( !stk.empty()) stk2.push(stk.pop());


//         String ans = "";
//         while( !stk2.empty()){
//             String temp = stk2.pop();
//             ans+="/";
//             ans+=temp;
//         }
        
//         return ans;
//     }
// }



class Solution {
    public String simplifyPath(String path) {
        String[] dictionary = path.split("/");
        Stack<String> stk = new Stack<>();

        for(String str : dictionary){
            if(str.equals("..")){
                if(!stk.empty()){
                    stk.pop();
                }
            } 
            else if(str.equals(".") || str.equals("")){
                // do nothing
            } 
            else{
                stk.push(str);
            }
        }

        String ans = "";
        for(String dir : stk){
            ans += "/" + dir;
        }

        return ans.length() == 0 ? "/" : ans;
    }
}
