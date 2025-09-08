class Solution {
    bool isContainsZero( int n){
        int temp = n;
        bool foundZero = false;
        while(temp){
            if(temp % 10 == 0){
                foundZero = true;
                break;
            } 
            temp /=10;
        }

        return foundZero;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++){
            if(! isContainsZero(i)){
               int req = n - i;
               if( ! isContainsZero(req)) return {i, req};
            }
        }
        return {-1, -1}; // this is just to convent compiler to not give any error
    }
};
