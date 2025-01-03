/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    let  diameter  = [0];
    height(root, diameter);
    return  diameter[0];
};

function height(root, diameter){

    if(root == null) return 0;

    let leftHeight = height(root.left, diameter);
    let rightHeight = height(root.right, diameter);

    diameter[0] =  Math.max( diameter[0], leftHeight+rightHeight );

    return Math.max(leftHeight , rightHeight ) + 1;

}
