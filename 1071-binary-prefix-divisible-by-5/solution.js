/**
 * @param {number[]} nums
 * @return {boolean[]}
 */
var prefixesDivBy5 = function(nums) {
    let rem = 0;
    let result = [];

    for(let x of nums){
        rem = (rem * 2 + x) % 5;
        result.push(rem == 0);
    }

    return result;
};
