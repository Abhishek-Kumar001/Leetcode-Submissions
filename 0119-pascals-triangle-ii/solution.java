class Solution {
    public List<Integer> getRow(int rowIndex) {
        // Create a list to store the elements of the current row in Pascal's Triangle
        List<Integer> l = new ArrayList<>();

        // Iterate through each row up to the specified rowIndex
        for (int i = 0; i <= rowIndex; i++) 
        {
            // Create an array dp to represent the current row
            int[] dp = new int[i + 1];

            // Set the first and last elements of the row to 1
            dp[0] = 1;
            dp[dp.length - 1] = 1;

            // Calculate the values for the non-edge elements in the row
            for (int j = 1; j < dp.length - 1; j++) 
            {
                // The value at position j is the sum of the two elements from the previous row
                dp[j] = l.get(j - 1) + l.get(j);
            }

            // Clear the list to prepare for the next row
            l.clear();

            // Convert the array to a List and add it to the list l
            for (int num : dp) {
                l.add(num);
            }
        }

        // Return the list representing the rowIndex-th row in Pascal's Triangle
        return l;
    }
}

