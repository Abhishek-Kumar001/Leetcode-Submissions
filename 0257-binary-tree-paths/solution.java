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

        String s = new String("");
        pathAdd(root,s, ansList);
        return ansList;
    }
    public void pathAdd(TreeNode root,String s,List<String> ansList){
        if(root == null) return ;
        if(root.left == null && root.right == null){
            s+=root.val;
            ansList.add(s);
            return;
        }
        String no = Integer.toString(root.val);
        s+=no;
        s+="->";

        //now make left & right calls
        pathAdd(root.left, s, ansList);
        pathAdd(root.right, s, ansList);
    }
}
