/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} k
 * @return {number[]}
 */
var distanceK = function(root, target, k) {
    //find the target node and also store the parent nodes
    let parent = new Map();
    let queue = [root];
    for(let root of queue){
        if(root.left ) {
            parent.set(root.left, root);
            queue.push(root.left);
        }
        if(root.right ){
           parent.set(root.right, root);
           queue.push(root.right);

           if(root == target) break;
        }
    }
                 // 2nd way to  create parent child node
    // // Map to store parent references
    // const parent = new Map();

    // // Helper function to populate parent map
    // const setParent = (node, par = null) => {
    //     if (!node) return;
    //     parent.set(node, par);
    //     setParent(node.left, node);
    //     setParent(node.right, node);
    // };

    // // Populate parent references
    // setParent(root);


    // console.log(parent);



    let distanceQ = [target];
    let visited = new Set();
    visited.add(target);
    let cnt = 0;
    let lastInd = 0;
    for(let i=0; i<distanceQ.length; ){
        if(cnt == k) break; // must be here not at last

        let sizeee = distanceQ.length;
        for(let j=i; j<sizeee; j++){
            let node = distanceQ[j];
            let parentNode = parent.get(node)
            if( parentNode  &&  !visited.has(parentNode)){
                distanceQ.push(parentNode);
                visited.add(parentNode);
            } 
                

            if(node.left && !visited.has(node.left)){
                distanceQ.push( node.left );
                visited.add(node.left)
            }
                

            if(node.right  && !visited.has(node.right)){
                distanceQ.push( node.right );
                visited.add(node.right)
            }
                
        }

        cnt++;
        i=sizeee;  // not i+=sizeee;
        lastInd = i;

        // if(cnt == k) break;    // not here
    }

    let ans = [];

    for(let i=lastInd; i<distanceQ.length; i++) ans.push(distanceQ[i].val);

    return ans;
};
