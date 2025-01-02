/**
 * @param {number[]} weights
 * @param {number} days
 * @return {number}
 */
var shipWithinDays = function(weights, days) {
    let mini = Math.min(...weights);
    let maxi = Math.max(...weights);

    if(weights.length == days) return maxi;

    let sum = weights.reduce((val, curr)=> val+=curr, 0);

    let s=maxi, e=sum;
    let ans =-1;
    while(s<=e){
        let mid = s + Math.floor((e-s)/2);

        if( isPossibleToShip(mid, weights, days)){
            ans = mid;
            e=mid-1;
        }else s= mid+1;
    }
    return ans;
};

function isPossibleToShip(cap, weights, days){
    let totalWeights = 0;
    let cntDays = 0;
    for(let w  of weights){
        if(totalWeights + w <= cap){
            totalWeights += w;
        }else{
            cntDays++;
            totalWeights = w;
        }
    }

    if(totalWeights != 0) cntDays++;

    return cntDays <= days;
}
