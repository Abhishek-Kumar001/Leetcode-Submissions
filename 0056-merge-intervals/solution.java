class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b )  -> a[0] - b[0]);
        int i=0;
        int end=intervals.length-1;
        while(i<=end-1){
         /*   if(intervals[i][0]>intervals[i+1][0]){
                int temp=intervals[i][0];
               intervals[i][0] = intervals[i+1][0];
                intervals[i+1][0]=temp;
            }  */
            if(intervals[i][1]>intervals[i+1][1]){
               int temp = intervals[i][1];
               intervals[i][1]  = intervals[i+1][1];
               intervals[i+1][1] = temp;
            }
            else if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i][1]=intervals[i+1][1];
                leftShift(intervals,i+1,end);
                end--;
                if(i>0)   { i--;}
            }
            else{
               i++;
            }
        }
        int row=end+1;
        int ans[][]=new int[row][2];
        for(int j=0;j<row;j++){
            ans[j][0]=intervals[j][0];
            ans[j][1]=intervals[j][1];
        }
        return ans;
          
    }
    void leftShift(int[][] intervals, int start, int end){
        while(start<end){
            intervals[start][0]=intervals[start+1][0];
            intervals[start][1]=intervals[start+1][1];
            start++;
        }
    }
}
