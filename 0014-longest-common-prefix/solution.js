/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let ansPrefix = "";
    for(let i=0; i<strs[0].length; i++){
        let ch = strs[0][i];
        let flag = 0;
        for(let j=1; j<strs.length; j++){
            if(strs[j].length < i+1){
                flag = 1;
                break ;
            }else{
                if(strs[j][i]  != ch){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1) return ansPrefix;
        ansPrefix+=ch;
    }

    return ansPrefix;
};
