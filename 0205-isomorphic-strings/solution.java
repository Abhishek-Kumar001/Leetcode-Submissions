class Solution {
    public boolean isIsomorphic(String s, String t) {
        int  sMap[] = new int[256];
        int tMap[] = new int[256];

        for(int i=0; i<256; i++){
            sMap[i] = -1;
            tMap[i] = -1;
        }

        for(int i=0; i<s.length(); i++){
            if(sMap[s.charAt(i)] == -1 && tMap[t.charAt(i)] == -1){
                sMap[s.charAt(i)] = t.charAt(i);
                tMap[t.charAt(i)] = s.charAt(i);

                System.out.println("sMap[s.charAt(i)] " + sMap[s.charAt(i)] );
                System.out.println("tMap[t.charAt(i)]" + tMap[t.charAt(i)]);
            }else{
                System.out.println("(s.charAt(i) != tMap[t.charAt(i)]  || sMap[s.charAt(i)] !=  t.charAt(i) ) = " + s.charAt(i)  + " " + tMap[t.charAt(i)]  + " - " + sMap[s.charAt(i)] + " " + t.charAt(i) );
                if((s.charAt(i) != tMap[t.charAt(i)]  || sMap[s.charAt(i)] !=  t.charAt(i) )) return false;
            }
        }

        return true;
    }
}
