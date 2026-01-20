class Solution {
    private Map<Integer, Integer> mpp = new HashMap<>();
    public int minSwapsCouples(int[] row) {
        for(int i=0; i<row.length; i++)
           mpp.put(row[i], i);

        int swapCnt = 0;
        for(int i=0; i<row.length; i+=2){
            int first = row[i];
            int second = first ^ 1;

            if(row[i+1] != second){
                swapCnt++;
                // do swaping
                swap(row, i+1, mpp.get(second));
            }
        }
        return swapCnt;
    }

    public void swap(int []arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        // now update the position of arr[i] and arr[j] with new position in map
        mpp.put(arr[i], i);
        mpp.put(arr[j], j);
    }
}
