/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ansList = new ArrayList<String>();
        String path = "";

        if(root == null) return ansList;

        helper(root, ansList, path);
        return ansList;
    }

    public void helper(TreeNode root, List<String> ansList, String path){
        if(root == null) return ;
        if(root.left == null && root.right == null){
            path+=(root.val);
            ansList.add(path);
            return ;
        }

        helper(root.left,  ansList, path + root.val + "->");
        helper(root.right, ansList, path + root.val + "->");


    }
}
