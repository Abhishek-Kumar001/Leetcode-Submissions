/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let mpp = new Map();
    mpp.set('I', 1);
    mpp.set('V', 5);
    mpp.set('X', 10);
    mpp.set('L', 50);
    mpp.set('C', 100);
    mpp.set('D', 500);
    mpp.set('M', 1000);

    let no = 0;
    for(let i=0; i<s.length; i++){
         no+=mpp.get(s[i]);

         if( i != 0  && mpp.get(s[i]) > mpp.get(s[i-1])  ){
            no = no-(2*mpp.get(s[i-1]));
         }
    }
    return no;
};
