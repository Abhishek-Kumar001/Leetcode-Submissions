/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function(arr, k) {
    let cntMissing = 0;
    let lastNo = 0;
    for(let x of arr){
        let missingNosBtLast2Nos  =  x - lastNo-1;

        if(cntMissing + missingNosBtLast2Nos >= k){
            let req =  k-cntMissing;
            // console.log("hey");
            return lastNo + req; 
        }

        lastNo = x;
        cntMissing +=missingNosBtLast2Nos;
    }
    
    let req =  k-cntMissing;
    return lastNo + req; 
};
