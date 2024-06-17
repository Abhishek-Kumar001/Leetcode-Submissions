class Solution {
    public String reverseVowels(String s) {
        String volStr = "aeiouAEIOU";
        char []charArr = s.toCharArray();

        int start = 0, end = s.length()-1;
        while(start<end){
           while(start<=end){
            if(volStr.indexOf( charArr[start]) != -1){
                break;
            }
            else start++;
           }

           while(start<=end){
            if(volStr.indexOf( charArr[end]) != -1){
                break;
            }else end--;
           }

           if(start < end){
            // swap
            char temp = charArr[start];
            charArr[start] = charArr[end];
            charArr[end] = temp;

            start++;
            end--;
           }


        }
        return new String(charArr);
    }
}
