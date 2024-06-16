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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ansList = new ArrayList<Integer>();

        preorderHelper(ansList, root);
        return ansList;
    }
    public void preorderHelper(List<Integer> ansList, TreeNode root){
        if(root == null) return;

        ansList.add(root.val);
        preorderHelper(ansList, root.left);
        preorderHelper(ansList, root.right);

    }
}
