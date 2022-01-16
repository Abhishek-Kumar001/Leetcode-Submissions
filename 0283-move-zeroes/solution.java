class Solution {
    public void moveZeroes(int[] nums) {
     int  end= nums.length;
        for(int i=0;i<end;i++){
            if(nums[i]==0){
                leftRotate(nums,i,end);
                
            if(nums[i]==0)
                i--;
                
                end--;
            }
        }
    }
    void  leftRotate(int nums[],int start,int end){
      for(int i=start;i<end-1;i++)
          nums[i]=nums[i+1];
        
        nums[end-1]=0;
    } 
}
