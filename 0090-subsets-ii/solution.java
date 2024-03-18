class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
		List<List<Integer>> ansList = new ArrayList<>();
		helper(0, nums, new ArrayList<>(), ansList);
        return ansList;
    }
    
    public static void helper(int ind, int input[], List<Integer> ds, List<List<Integer>>         ansList){
		ansList.add(new ArrayList<>(ds) );


		for( int i=ind; i<input.length; i++){
			if( i != ind  && input[i] == input[i-1])
			   continue;

			ds.add( input[i]);
			helper( i+1,  input, ds, ansList);
			ds.remove(ds.size()-1);
		}
	}
}
