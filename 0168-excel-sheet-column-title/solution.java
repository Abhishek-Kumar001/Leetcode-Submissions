class Solution {
    public String convertToTitle(int columnNumber) {
        // char ch[]= {' ','A','B','C','D','E','F','G','H','I','J',
        //    'K','L','M','N','O','P','Q','R','S','T','U','V',
        //    'W','X','Y','Z'};

        // now run loop
        String tempStr = "";
        while(columnNumber > 0){
            int rem = (columnNumber-1) % 26; 
             
            tempStr+= (char)(rem + 'A');
            columnNumber= (columnNumber-1)/26;
        }

        // now reverse the string;
        String ansStr="";
        for(int i=tempStr.length()-1; i>=0; i--){
            ansStr+=tempStr.charAt(i);
        }

        return ansStr;
    }
}
