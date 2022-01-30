class Solution {
    public void nextPermutation(int[] nums) {
        int i;
        for( i=nums.length-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        if(i<0){
            i=0;
              for(i=0;i<nums.length/2;i++){
            swap(nums,i,nums.length-i-1);
        }
        }
        else{
            int k=i;
            int j;
            for(j=nums.length-1;j>i;j--){
                if(nums[j]>nums[i]){
                    break;
                }
            }
              swap(nums,j,i);
              for(i=k+1;i<nums.length-1;i++){
                  for(int m=i+1;m<nums.length;m++){
                      if(nums[i]>nums[m])
                        swap(nums,i,m);
                
                  }
               }
        }
      
    }
    void swap(int nums[], int j, int i){
        int temp=nums[j];
        nums[j]=nums[i];
        nums[i]=temp;
    }
}
