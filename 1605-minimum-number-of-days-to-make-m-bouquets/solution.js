/**
 * @param {number[]} bloomDay
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minDays = function(bloomDay, m, k) {
    if( bloomDay.length  < m*k) return -1;

    let mini = Math.min(...bloomDay);
    let maxi = Math.max(...bloomDay);

    let s=mini, e= maxi;
    let ans=-1;

    while(s<=e){
        let mid = s + Math.floor( (e-s)/2);

        if( canWeMakeMbouquets(mid, bloomDay, m, k)){
            ans = mid;
            e=mid-1;
        }else s=mid+1;
    }
    return ans;
};

function canWeMakeMbouquets(mid, bloomDay, m, k){
    let cnt=0, noOfBouquets =0;
    for(let x of bloomDay){
        if(x <= mid) cnt++;
        else{
            noOfBouquets +=  Math.floor(cnt/k);
            cnt=0;
        }
    }

    noOfBouquets +=  Math.floor(cnt/k);

    return noOfBouquets >= m ;
}
