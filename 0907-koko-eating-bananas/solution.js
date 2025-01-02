/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    let maxi =1;
    for(let x of piles){
        if(x > maxi) maxi = x;
    }

    let s=1, e=maxi;
    let ans=maxi;
    while(s<=e){
        let mid = s + Math.floor( (e-s)/2 );

        let result = isPossibleWithMidSpeed(mid, piles, h);

        if(result == 1) {
            ans = mid;
            e= mid-1;
        }
        else s=mid+1;
    }
    return  ans;
};

var isPossibleWithMidSpeed = function(mid, piles, h){
    let timeTaken = 0;
    for(let x of piles){
        let time = Math.ceil(x/mid);
        timeTaken +=time;
        if(timeTaken > h) return 2; // we have exceed max allowed time
    }
    return 1;  // here totalTime is either less than n or equal to n
}
