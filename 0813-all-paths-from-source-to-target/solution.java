class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        
        path.add(0);
        dfs(0, graph, path, ans);
        
        return ans;
    }

    private void dfs(int node, int[][] graph, List<Integer> path, List<List<Integer>> ans) {
        // base case: reached target
        if (node == graph.length - 1) {
            ans.add(new ArrayList<>(path));
            return;
        }

        // explore neighbors
        for (int neighbor : graph[node]) {
            path.add(neighbor);
            dfs(neighbor, graph, path, ans);
            path.remove(path.size() - 1); // backtrack
        }
    }
}
