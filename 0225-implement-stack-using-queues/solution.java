class MyStack {
                 //SAME CODE WITH COMMENTS         
    
    //creating 2 queues
    Queue<Integer>    q= new LinkedList<>();
    Queue<Integer>   help = new LinkedList<>();
    public MyStack() {

    }
    
    public void push(int x) {
        q.add(x);
    }
    
    public int pop() {
        //last ele ko chood ke baki sab ko helper q me dal de
        while(q.size() > 1 ){
            help.add( q.remove() );
        }
        
        //this is the last element
        int data= q.remove();
        
        //wapas original q me dal de
        while(  ! help.isEmpty() ){
            q.add( help.remove() );
        }
        
        return data;
    }
    
    public int top() {
        //last ele ko chood ke baki sab ko helper q me dal de
        while(q.size() > 1 ){
            help.add( q.remove() );
        }
        
        //this is the last element
        int data= q.remove();
        
        //last ele ko v helper  me dal de b/c hame top find karna hai 
        help.add( data );
        
        //wapas original q me dal de
        while(  ! help.isEmpty() ){
            q.add( help.remove() );
        }
        
        return data; 
    }
    
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
