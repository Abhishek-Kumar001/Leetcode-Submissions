class RecentCounter {
    int  counter;
    ArrayList<Integer> al= new ArrayList<>();
    public RecentCounter() {
         counter=0;
    }
    
    public int ping(int t) {
        al.add(t);
        
        //find when was past 3000 milliseconds  
        int last_time=t-3000  , i=0;
        for( i=0;i<al.size(); i++){
            if(al.get(i) >=last_time){
                break;
            }
        }
        //total ping = al.size()-i;
        return al.size()-i;
           
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
