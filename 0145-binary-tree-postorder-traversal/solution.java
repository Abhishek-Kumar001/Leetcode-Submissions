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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ansList = new ArrayList<Integer>();

        postorderHelper(ansList, root);
        return ansList;
    }
    public void postorderHelper(List<Integer> ansList, TreeNode root){
        if(root == null) return;

        
        postorderHelper(ansList, root.left);
        postorderHelper(ansList, root.right);
        ansList.add(root.val);

    }
}
